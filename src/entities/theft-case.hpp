#pragma once

#include <vector>

#include <src/entities/vehicle.hpp>
#include <src/entities/entity.hpp>
#include <src/entities/vehicle.hpp>
#include <src/helpers/date-time.hpp>

struct TheftCaseDTO
{
    DateTime dateTime;
    std::string location;
    std::string hackingMethod;
    std::string licensePlate;
    bool isFound;
};
struct TheftCaseStatisticDTO
{
    std::vector<std::string> mostPopularBrands;
    std::vector<std::string> mostPopularVehicleTypes;
};

class TheftCase : public Entity<TheftCase>
{
private:
    DateTime m_dateTime;
    std::string m_location;
    std::string m_hackingMethod;
    unsigned int m_vehicleId;
    bool m_isFound = false;

public:
    TheftCase(const DateTime dateTime, const std::string location, const std::string hackingMethod, 
        const unsigned int vehicleId);
    TheftCase(const unsigned int id, const DateTime dateTime, const std::string location, 
        const std::string hackingMethod, const unsigned int vehicleId, const bool isFound);
public:
    DateTime     getDateTime() const;
    std::string  getLocation() const;
    std::string  getHackingMethod() const;
    unsigned int getVehicleId() const;
    bool         getIsFound() const;

    void setFound();

};
