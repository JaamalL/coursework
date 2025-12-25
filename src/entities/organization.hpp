#pragma once

#include <string>
#include <vector>

#include <src/entities/entity.hpp>
#include <src/helpers/date-time.hpp>

struct OrganizationDTO
{
    std::string organizationName;
    std::string address;
    std::string managerFullName;
};

class Organization : public Entity<Organization>
{
private:
    std::string m_organizationName;
    std::string m_address;
    std::string m_managerFullName;
    std::vector<unsigned int> m_vehicleRecordIds;

public:
    Organization(const std::string organizationName, const std::string address, 
        const std::string managerFullName, std::vector<unsigned int>& vehicleRecordIds);
    Organization(const unsigned int id, const std::string organizationName, 
        const std::string address, const std::string managerFullName, 
        std::vector<unsigned int>& vehicleRecordIds);
public:
    std::string                       getOrganizationName() const;
    std::string                       getAddress() const;
    std::string                       getManagerFullName() const;
    const std::vector<unsigned int>&  getVehicleRecordIds() const;

};
