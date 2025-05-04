#pragma once

#include <ctime>

#include <src/entities/vehicle.hpp>

class TheftCase
{
private:
    time_t m_dateTime;
    std::string m_location;
    std::string m_hackingMethod;
    Vehicle* m_vehicle;
    bool m_isFound = false;

public:
    TheftCase(const time_t dateTime, const std::string location, const std::string hackingMethod, Vehicle& vehicle);
    ~TheftCase() = default;
public:
    time_t      getDateTime() const;
    std::string getLocation() const;
    std::string getHackingMethod() const;
    Vehicle*    getVehicle() const;
    bool        getIsFound() const;

    void setIsFound(const bool isFound);

};
