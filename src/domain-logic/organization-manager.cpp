#include "src/data/i-vehicle-record-repo.hpp"
#include "src/entities/vehicle-record.hpp"
#include <stdexcept>

#include <src/domain-logic/organization-manager.hpp>
#include <src/domain-logic/validator.hpp>

OrganizationManager::OrganizationManager(IOrganizationRepo& organizationRepo, 
    IVehicleRepo& vehicleRepo, IVehicleRecordRepo& vehicleRecordRepo)
:
    m_organizationRepo(organizationRepo),
    m_vehicleRepo(vehicleRepo),
    m_vehicleRecordRepo(vehicleRecordRepo)
{}

void OrganizationManager::createOrganization(const std::string organizationName, 
    const std::string address, const std::string managerFullName, 
    std::vector<VehicleRecordDTO>& vehicleRecords)
{
    if (m_organizationRepo.getByName(organizationName) != nullptr)
        throw std::runtime_error("Error: organization name exists");

    std::vector<unsigned int> vehicleRecordIds;
    for (unsigned int i = 0; i < vehicleRecords.size(); ++i)
    {
        Vehicle* veh = m_vehicleRepo.getByLicensePlate(vehicleRecords[i].licensePlate);
        if (veh == nullptr)
            throw std::runtime_error("Error: vehicle not exists");

        VehicleRecord* vehRec = new VehicleRecord(vehicleRecords[i].dateTime, 
            veh->getId());
        
        m_vehicleRecordRepo.add(vehRec);
        vehicleRecordIds.push_back(vehRec->getId());
    }

    m_organizationRepo.add(new Organization(organizationName, address, managerFullName, 
        vehicleRecordIds));
}

std::vector<OrganizationDTO> OrganizationManager::getBySeries(const std::string series) const
{
    std::vector<OrganizationDTO> out;
    const std::vector<Organization*>& organizations = m_organizationRepo.getAll();
    for (unsigned int i = 0; i < organizations.size(); ++i)
    {
        const std::vector<unsigned int>& recs = organizations[i]->getVehicleRecordIds();
        for (unsigned int j = 0; j < recs.size(); ++j)
        {
            VehicleRecord* vehRec = m_vehicleRecordRepo.getById(recs[j]);
            if (Validator::getLicensePlateSeries(
                m_vehicleRepo.getById(vehRec->getVehicleId())->getLicensePlate()) != series)
                continue;
            
            out.push_back({ 
                organizations[i]->getOrganizationName(), 
                organizations[i]->getAddress(), 
                organizations[i]->getManagerFullName() 
            });
            break;
        }
    }

    return out;
}
std::vector<OrganizationDTO> OrganizationManager::getByRecievedPeriod(const DateTime start, 
    const DateTime end) const
{
    std::vector<OrganizationDTO> out;
    const std::vector<Organization*>& organizations = m_organizationRepo.getAll();
    for (unsigned int i = 0; i < organizations.size(); ++i)
    {
        const std::vector<unsigned int>& rec = organizations[i]->getVehicleRecordIds();
        for (unsigned int j = 0; j < rec.size(); ++j)
        {
            VehicleRecord* vehRec = m_vehicleRecordRepo.getById(rec[i]);

            if (vehRec->getDateTime() < start || vehRec->getDateTime() > end)
                continue;
            
            out.push_back({ 
                organizations[i]->getOrganizationName(), 
                organizations[i]->getAddress(), 
                organizations[i]->getManagerFullName()
            });
            break;
        }
    }

    return out;
}
