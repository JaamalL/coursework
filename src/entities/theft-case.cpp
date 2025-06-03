#include <src/entities/theft-case.hpp>

TheftCase::TheftCase(const DateTime dateTime, const std::string location, const std::string hackingMethod, 
    const unsigned int vehicleId)
:
    m_dateTime(dateTime),
    m_location(location),
    m_hackingMethod(hackingMethod),
    m_vehicleId(vehicleId)
{}
TheftCase::TheftCase(const unsigned int id, const DateTime dateTime, const std::string location, 
    const std::string hackingMethod, const unsigned int vehicleId, const bool isFound)
:
    Entity(id),
    m_dateTime(dateTime),
    m_location(location),
    m_hackingMethod(hackingMethod),
    m_vehicleId(vehicleId),
    m_isFound(isFound)
{}

DateTime     TheftCase::getDateTime() const { return m_dateTime; }
std::string  TheftCase::getLocation() const { return m_location; }
std::string  TheftCase::getHackingMethod() const { return m_hackingMethod; }
unsigned int TheftCase::getVehicleId() const { return m_vehicleId; }
bool         TheftCase::getIsFound() const { return m_isFound; }

void TheftCase::setFound() { m_isFound = true; }
