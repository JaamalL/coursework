#include <stdexcept>

#include <src/domain-logic/vehicle-manager.hpp>

VehicleManager::VehicleManager(IVehicleRepo& vehicleRepo, IOwnerRepo& ownerRepo)
:
    m_vehicleRepo(vehicleRepo),
    m_ownerRepo(ownerRepo)
{}

void VehicleManager::createVehicle(const std::string licensePlate, const Vehicle::VehicleType type, 
    const std::string brand, const unsigned int releaseYear, const float engineVolume, 
    const std::string engineSerialNumber, const std::string chassisSerialNumber, 
    const std::string bodySerialNumber, const std::string color, const bool isPassedInspection, 
    const bool isAccident, const std::string ownerPhoneNumber)
{
    if (m_vehicleRepo.getByLicensePlate(licensePlate) != nullptr)
        throw std::runtime_error("Error: license plate exists");

    Owner* owner = m_ownerRepo.getByPhoneNumber(ownerPhoneNumber);

    if (owner == nullptr)
        throw std::runtime_error("Error: owner phone number not exists");

    m_vehicleRepo.add(new Vehicle(licensePlate, type, brand, releaseYear, engineVolume, 
        engineSerialNumber, chassisSerialNumber, bodySerialNumber, color, isPassedInspection, 
        isAccident, owner->getId()));
}

std::unique_ptr<VehicleDTO> VehicleManager::getVehicleByLicensePlate(
    const std::string licensePlate) const
{
    Vehicle* veh = m_vehicleRepo.getByLicensePlate(licensePlate);

    if (veh == nullptr)
        throw std::runtime_error("Error: license plate not exists");

    return std::make_unique<VehicleDTO>(VehicleDTO{ 
        licensePlate, 
        Vehicle::vehicleTypeToString(veh->getType()), veh->getBrand(), 
        veh->getReleaseYear(), 
        veh->getEngineVolume(), 
        veh->getEngineSerialNumber(), 
        veh->getChassisSerialNumber(), 
        veh->getBodySerialNumber(), 
        veh->getColor(), 
        veh->getIsPassedInspection(), 
        veh->getIsAccident() 
    });
}
