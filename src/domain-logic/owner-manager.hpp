#pragma once

#include <memory>

#include <src/data/i-owner-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>

class OwnerManager
{
private:
    IOwnerRepo& m_ownerRepo;
    IVehicleRepo& m_vehicleRepo;

public:
    OwnerManager(IOwnerRepo& ownerRepo, IVehicleRepo& vehicleRepo);
public:
    void createOwner(const std::string phoneNumber, const std::string surname, const std::string name, 
        const std::string patronymic, const std::string address);

    std::unique_ptr<OwnerDTO> getOwnerByLicensePlate(const std::string licensePlate) const;
    std::vector<OwnerDTO> getOwnerByNotPassedInspection() const;
    
};
