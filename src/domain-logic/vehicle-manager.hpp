#pragma once

#include <memory>

#include <src/data/i-owner-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>
#include <src/entities/vehicle.hpp>

class VehicleManager
{
private:
    IVehicleRepo& m_vehicleRepo;
    IOwnerRepo& m_ownerRepo;

public:
    VehicleManager(IVehicleRepo& vehicleRepo, IOwnerRepo& ownerRepo);
public:
    void createVehicle(const std::string licensePlate, const Vehicle::VehicleType type, const std::string brand, 
        const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
        const std::string chassisSerialNumber, const std::string bodySerialNumber, const std::string color, 
        const bool isPassedInspection, const bool isAccident, const std::string ownerPhoneNumber);

    std::unique_ptr<VehicleDTO> getVehicleByLicensePlate(const std::string licensePlate) const;
    std::vector<std::string> getVehicleLicensePlates() const;

};
