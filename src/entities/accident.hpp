#pragma once

#include <ctime>
#include <vector>

#include <src/entities/vehicle.hpp>
#include <src/entities/entity.hpp>

class Accident : public Entity<Accident>
{
public:
    enum AccidentType
    {
        PEDESTRAIN_HIT,
        OBSTACLE_HIT,
        HEAD_ON_HIT,
        REAR_END,
        SIDE_HIT,
        OTHER
    };

private:
    time_t m_dateTime; // TODO change to DateTime helper
    AccidentType m_accidentType;
    std::string m_location;
    std::vector<unsigned int> m_participantVehicleIds;
    std::string m_description;
    unsigned int m_injuredCount;
    double m_damageCost;
    std::string m_cause;
    std::string m_roadConditions;
    std::vector<unsigned int> m_escapedVehicleIds;
    
public:
    Accident(const time_t dateTime, const AccidentType accidentType, const std::string location, std::vector<unsigned int>& participantsVehicles,
        const std::string description, const unsigned int injuredCount, const double damageCost, const std::string cause, const std::string roadConditions, 
        std::vector<unsigned int>& escapedVehicles);
    ~Accident() = default;
public:
    time_t                     getDateTime() const;
    AccidentType               getAccidentType() const;
    std::string                getLocation() const;
    std::vector<unsigned int>& getParticipantVehicleIds() const;
    std::string                getDescription() const;
    unsigned int               getInjuredCount() const;
    double                     getDamageCost() const;
    std::string                getCause() const;
    std::string                getRoadConditions() const;
    std::vector<unsigned int>& getEscapedVehicleIds() const;

};
