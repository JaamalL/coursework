#pragma once

#include <vector>

#include <src/entities/organization.hpp>
#include <src/helpers/date-time.hpp>
#include <src/data/i-organization-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>

class OrganizationManager
{
private:
    IOrganizationRepo& m_organizationRepo;
    IVehicleRepo& m_vehicleRepo;

public:
    OrganizationManager(IOrganizationRepo& organizationRepo, IVehicleRepo& vehicleRepo);
public:
    void createOrganization(const std::string organizationName, const std::string address, 
        const std::string managerFullName, std::vector<VehicleRecordDTO>& vehicleRecords);

    std::vector<OrganizationDTO> getBySeries(const std::string series) const;
    std::vector<OrganizationDTO> getByRecievedPeriod(const DateTime start, const DateTime end) const;

};
