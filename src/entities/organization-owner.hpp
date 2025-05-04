#pragma once

#include <src/entities/owner.hpp>

class OrganizationOwner : public Owner
{
private:
    std::string m_organizationName;
    std::string m_area;
    std::string m_address;
    std::string m_managerFullName;
    std::vector<Vehicle*> m_vehicles;

public:
    OrganizationOwner(const std::string organizationName, const std::string area, const std::string address, const std::string managerFullName);
    ~OrganizationOwner() = default;
public:
    std::string            getOrganizationName() const;
    std::string            getArea() const;
    std::string            getAddress() const;
    std::string            getManagerFullName() const;
    std::vector<Vehicle*>& getVehicles() const;

    void setOrganizationName(const std::string organizationName);
    void setArea(const std::string area);
    void setAddress(const std::string address);
    void setManagerFullName(const std::string managerFullName);

};
