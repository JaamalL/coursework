#include <stdexcept>

#include <src/domain-logic/organization-manager.hpp>
#include <src/domain-logic/validator.hpp>

OrganizationManager::OrganizationManager(IOrganizationRepo& organizationRepo, 
    IVehicleRepo& vehicleRepo)\
:
    m_organizationRepo(organizationRepo),
    m_vehicleRepo(vehicleRepo)
{}

void OrganizationManager::createOrganization(const std::string organizationName, 
    const std::string address, const std::string managerFullName, 
    std::vector<VehicleRecordDTO>& vehicleRecords)
{
    if (m_organizationRepo.getByName(organizationName) != nullptr)
        throw std::runtime_error("Error: organization name exists");

    std::vector<Organization::VehicleRecord> vehicleRec;
    for (unsigned int i = 0; i < vehicleRecords.size(); ++i)
    {
        Vehicle* veh = m_vehicleRepo.getByLicensePlate(vehicleRecords[i].licensePlate);
        if (veh == nullptr)
            throw std::runtime_error("Error: vehicle not exists");

        vehicleRec.push_back({ vehicleRecords[i].dateTime, veh->getId() });
    }

    m_organizationRepo.add(new Organization(organizationName, address, managerFullName, 
        vehicleRec));
}

std::vector<OrganizationDTO> OrganizationManager::getBySeries(const std::string series) const
{
    std::vector<OrganizationDTO> out;
    const std::vector<Organization*>& organizations = m_organizationRepo.getAll();
    for (unsigned int i = 0; i < organizations.size(); ++i)
    {
        const std::vector<Organization::VehicleRecord>& rec = organizations[i]->getVehicleRecords();
        for (unsigned int j = 0; j < rec.size(); ++j)
        {
            Vehicle* veh = m_vehicleRepo.getById(rec[i].vehicleId);
            if (Validator::getLicensePlateSeries(veh->getLicensePlate()) == series)
                out.push_back({ organizations[i]->getOrganizationName(), 
                    organizations[i]->getAddress(), 
                    organizations[i]->getManagerFullName() });
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
        const std::vector<Organization::VehicleRecord>& rec = organizations[i]->getVehicleRecords();
        for (unsigned int j = 0; j < rec.size(); ++j)
        {
            if (rec[j].dateTime >= start && rec[j].dateTime <= end)
                out.push_back({ organizations[i]->getOrganizationName(), 
                    organizations[i]->getAddress(), 
                    organizations[i]->getManagerFullName() });
        }
    }

    return out;
}
