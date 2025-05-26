#pragma once

#include <string>
#include <vector>

#include <src/entities/entity.hpp>
#include <src/helpers/date-time.hpp>

struct OrganizationDTO
{
    std::string organizationName;
    std::string m_address;
    std::string m_managerFullName;
};
struct VehicleRecordDTO
{
    DateTime dateTime;
    std::string licensePlate;
};

class Organization : public Entity<Organization>
{
public:
    struct VehicleRecord
    {
        DateTime dateTime;
        unsigned int vehicleId;
    };

private:
    std::string m_organizationName;
    std::string m_address;
    std::string m_managerFullName;
    std::vector<VehicleRecord> m_vehicleRecords;

public:
    Organization(const std::string organizationName, const std::string address, 
        const std::string managerFullName, std::vector<VehicleRecord>& vehicleRecords);
    Organization(const unsigned int id, const std::string organizationName, 
        const std::string address, const std::string managerFullName, 
        std::vector<VehicleRecord>& vehicleRecords);
public:
    std::string                       getOrganizationName() const;
    std::string                       getAddress() const;
    std::string                       getManagerFullName() const;
    const std::vector<VehicleRecord>& getVehicleRecords() const;

};
