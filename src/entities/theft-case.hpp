#pragma once

#include <ctime>

#include <src/entities/vehicle.hpp>
#include <src/entities/entity.hpp>

class TheftCase : Entity<TheftCase>
{
private:
    time_t m_dateTime; // TODO change to DateTime helper
    std::string m_location;
    std::string m_hackingMethod;
    unsigned int m_vehicleId;
    bool m_isFound = false;

public:
    TheftCase(const time_t dateTime, const std::string location, const std::string hackingMethod, const unsigned int vehicleId);
    ~TheftCase() = default;
public:
    time_t       getDateTime() const;
    std::string  getLocation() const;
    std::string  getHackingMethod() const;
    unsigned int getvehicleId() const;
    bool         getIsFound() const;

    void setIsFound(const bool isFound);

};
