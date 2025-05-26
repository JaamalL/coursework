#include <src/entities/organization.hpp>

Organization::Organization(const std::string organizationName, const std::string address, 
    const std::string managerFullName, std::vector<VehicleRecord>& vehicleRecords)
:
    m_organizationName(organizationName),
    m_address(address),
    m_managerFullName(managerFullName),
    m_vehicleRecords(vehicleRecords)
{}
Organization::Organization(const unsigned int id, const std::string organizationName, 
    const std::string address, const std::string managerFullName, 
    std::vector<VehicleRecord>& vehicleRecords)
:
    Entity(id),
    m_organizationName(organizationName),
    m_address(address),
    m_managerFullName(managerFullName),
    m_vehicleRecords(vehicleRecords)
{}

std::string                       Organization::getOrganizationName() const { return m_organizationName; }
std::string                       Organization::getAddress() const { return m_address; }
std::string                       Organization::getManagerFullName() const { return m_managerFullName; }
const std::vector<Organization::VehicleRecord>& Organization::getVehicleRecords() const { return m_vehicleRecords; }
