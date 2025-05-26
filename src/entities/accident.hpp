#pragma once

#include <ctime>
#include <vector>

#include <src/entities/vehicle.hpp>
#include <src/entities/entity.hpp>
#include <src/helpers/date-time.hpp>

struct AccidentStatisticDTO
{
    unsigned int total = 0;
    unsigned int totalInjuredCount = 0;
    unsigned int totalParticipantVehicles = 0;
    unsigned int totalEscapedVehicles = 0;
    float totalDamageCost = 0;
};
struct AccidentAnalysisDTO
{
    std::vector<std::string> mostDanagerousLocations;
    std::string mostPopularCouse;
};
struct AccidentDrunkDTO
{
    unsigned int total = 0;
    float part = 0;
};

class Accident : public Entity<Accident>
{
public:
    enum class AccidentType
    {
        PEDESTRAIN_HIT,
        OBSTACLE_HIT,
        HEAD_ON_HIT,
        REAR_END,
        SIDE_HIT,
        OTHER
    };

    enum class CauseType
    {
        DRUNK,
        BREAK_RULES,
        BREAKAGE,
        ROAD_CONDITIONS,
        OTHER
    };

private:
    DateTime m_dateTime;
    AccidentType m_accidentType;
    std::string m_location;
    std::vector<unsigned int> m_participantVehicleIds;
    std::string m_description;
    unsigned int m_injuredCount;
    float m_damageCost;
    CauseType m_cause;
    std::string m_roadConditions;
    std::vector<unsigned int> m_escapedVehicleIds;

    static std::string m_causeTypeStr[];
    
public:
    Accident(const DateTime dateTime, const AccidentType accidentType, const std::string location, 
        std::vector<unsigned int>& participantsVehicleIds, const std::string description, 
        const unsigned int injuredCount, const float damageCost, const CauseType cause, 
        const std::string roadConditions, std::vector<unsigned int>& escapedVehicleIds);
    Accident(const unsigned int id, const DateTime dateTime, const AccidentType accidentType, 
        const std::string location, std::vector<unsigned int>& participantsVehicleIds, 
        const std::string description, const unsigned int injuredCount, const float damageCost, 
        const CauseType cause, const std::string roadConditions, std::vector<unsigned int>& escapedVehicleIds);
public:
    DateTime                         getDateTime() const;
    AccidentType                     getAccidentType() const;
    std::string                      getLocation() const;
    const std::vector<unsigned int>& getParticipantVehicleIds() const;
    std::string                      getDescription() const;
    unsigned int                     getInjuredCount() const;
    float                            getDamageCost() const;
    CauseType                        getCause() const;
    std::string                      getRoadConditions() const;
    const std::vector<unsigned int>& getEscapedVehicleIds() const;

    static std::string causeTypeToString(const CauseType type);
    static bool isValidCauseType(const unsigned int type);

};
