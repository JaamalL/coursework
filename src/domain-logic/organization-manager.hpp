#pragma once

#include <vector>

#include <src/entities/organization.hpp>
#include <src/entities/vehicle-record.hpp>
#include <src/helpers/date-time.hpp>
#include <src/data/i-organization-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>
#include <src/data/i-vehicle-record-repo.hpp>

class OrganizationManager
{
private:
    IOrganizationRepo& m_organizationRepo;
    IVehicleRepo& m_vehicleRepo;
    IVehicleRecordRepo& m_vehicleRecordRepo;

public:
    OrganizationManager(IOrganizationRepo& organizationRepo, IVehicleRepo& vehicleRepo,
        IVehicleRecordRepo& vehicleRecordRepo);
public:
    void createOrganization(const std::string organizationName, const std::string address, 
        const std::string managerFullName, std::vector<VehicleRecordDTO>& vehicleRecords);

    std::vector<OrganizationDTO> getBySeries(const std::string series) const;
    std::vector<OrganizationDTO> getByRecievedPeriod(const DateTime start, const DateTime end) const;

};
