#include <stdexcept>

#include <src/domain-logic/owner-manager.hpp>

OwnerManager::OwnerManager(IOwnerRepo& ownerRepo, IVehicleRepo& vehicleRepo)
:
    m_ownerRepo(ownerRepo),
    m_vehicleRepo(vehicleRepo)
{}

void OwnerManager::createOwner(const std::string phoneNumber, const std::string surname, 
    const std::string name, const std::string patronymic, const std::string address)
{
    if (m_ownerRepo.getByPhoneNumber(phoneNumber) != nullptr)
        throw std::runtime_error("Error: phone number exists");

    m_ownerRepo.add(new Owner(phoneNumber, surname, name, patronymic, address));
}

std::unique_ptr<OwnerDTO> OwnerManager::getOwnerByLicensePlate(const std::string licensePlate) const
{
    Vehicle* veh = m_vehicleRepo.getByLicensePlate(licensePlate);

    if (veh == nullptr)
        throw std::runtime_error("Error: license plate not exists");

    Owner* owner = m_ownerRepo.getById(veh->getOwnerId());

    return std::make_unique<OwnerDTO>(OwnerDTO{
        owner->getPhoneNumber(),
        owner->getSurname(),
        owner->getName(),
        owner->getPatronymic(),
        owner->getAddress()
    });
}
std::vector<OwnerDTO> OwnerManager::getOwnersByNotPassedInspection() const
{
    std::vector<OwnerDTO> out;
    const std::vector<Vehicle*>& vehicles = m_vehicleRepo.getAll();

    for (unsigned int i = 0; i < vehicles.size(); ++i)
    {
        if (vehicles[i]->getIsPassedInspection())
            continue;

        Owner* owner = m_ownerRepo.getById(vehicles[i]->getOwnerId());

        out.push_back({
            owner->getPhoneNumber(),
            owner->getSurname(),
            owner->getName(),
            owner->getPatronymic(),
            owner->getAddress()
        });
    }
    
    return out;
}
