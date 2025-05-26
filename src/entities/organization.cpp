#include <src/entities/organization.hpp>

Organization::Organization(const std::string organizationName, const std::string address, 
    const std::string managerFullName, std::vector<unsigned int>& vehicleRecordIds)
:
    m_organizationName(organizationName),
    m_address(address),
    m_managerFullName(managerFullName),
    m_vehicleRecordIds(vehicleRecordIds)
{}
Organization::Organization(const unsigned int id, const std::string organizationName, 
    const std::string address, const std::string managerFullName, 
    std::vector<unsigned int>& vehicleRecordIds)
:
    Entity(id),
    m_organizationName(organizationName),
    m_address(address),
    m_managerFullName(managerFullName),
    m_vehicleRecordIds(vehicleRecordIds)
{}

std::string                       Organization::getOrganizationName() const { return m_organizationName; }
std::string                       Organization::getAddress() const { return m_address; }
std::string                       Organization::getManagerFullName() const { return m_managerFullName; }
const std::vector<unsigned int>&  Organization::getVehicleRecordIds() const { return m_vehicleRecordIds; }
