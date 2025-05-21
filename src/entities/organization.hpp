#pragma once

#include <string>
#include <vector>

#include <src/entities/entity.hpp>

class Organization : public Entity<Organization>
{
private:
    std::string m_organizationName;
    std::string m_area;
    std::string m_address;
    std::string m_managerFullName;
    std::vector<unsigned int> m_vehicleIds;

public:
    Organization(const std::string organizationName, const std::string area, const std::string address, 
        const std::string managerFullName, std::vector<unsigned int>& vehicleIds);
    ~Organization() = default;
public:
    std::string                getOrganizationName() const;
    std::string                getArea() const;
    std::string                getAddress() const;
    std::string                getManagerFullName() const;
    std::vector<unsigned int>& getVehicleIds() const;

    void setOrganizationName(const std::string organizationName);
    void setArea(const std::string area);
    void setAddress(const std::string address);
    void setManagerFullName(const std::string managerFullName);

};
