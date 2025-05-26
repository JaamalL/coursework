#include <src/entities/accident.hpp>

Accident::Accident(const DateTime dateTime, const AccidentType accidentType, const std::string location, 
    std::vector<unsigned int>& participantsVehicleIds, const std::string description, 
    const unsigned int injuredCount, const float damageCost, const CauseType cause, 
    const std::string roadConditions, std::vector<unsigned int>& escapedVehicleIds)
:
    m_dateTime(dateTime),
    m_accidentType(accidentType),
    m_location(location),
    m_participantVehicleIds(participantsVehicleIds),
    m_description(description),
    m_injuredCount(injuredCount),
    m_damageCost(damageCost),
    m_cause(cause),
    m_roadConditions(roadConditions),
    m_escapedVehicleIds(escapedVehicleIds)
{}
Accident::Accident(const unsigned int id, const DateTime dateTime, const AccidentType accidentType, 
    const std::string location, std::vector<unsigned int>& participantsVehicleIds, 
    const std::string description, const unsigned int injuredCount, const float damageCost, 
    const CauseType cause, const std::string roadConditions, std::vector<unsigned int>& escapedVehicleIds)
:
    Entity(id),
    m_dateTime(dateTime),
    m_accidentType(accidentType),
    m_location(location),
    m_participantVehicleIds(participantsVehicleIds),
    m_description(description),
    m_injuredCount(injuredCount),
    m_damageCost(damageCost),
    m_cause(cause),
    m_roadConditions(roadConditions),
    m_escapedVehicleIds(escapedVehicleIds)
{}

DateTime                         Accident::getDateTime() const { return m_dateTime; }
Accident::AccidentType           Accident::getAccidentType() const { return m_accidentType; }
std::string                      Accident::getLocation() const { return m_location; }
const std::vector<unsigned int>& Accident::getParticipantVehicleIds() const { return m_participantVehicleIds; }
std::string                      Accident::getDescription() const { return m_description; }
unsigned int                     Accident::getInjuredCount() const { return m_injuredCount; }
float                            Accident::getDamageCost() const { return m_damageCost; }
Accident::CauseType              Accident::getCause() const { return m_cause; }
std::string                      Accident::getRoadConditions() const { return m_roadConditions; }
const std::vector<unsigned int>& Accident::getEscapedVehicleIds() const { return m_escapedVehicleIds; }

std::string Accident::causeTypeToString(const CauseType type) { return m_causeTypeStr[(unsigned int)type]; }
bool Accident::isValidCauseType(const unsigned int type) { return type <= (unsigned int)CauseType::OTHER; }

std::string Accident::m_causeTypeStr[] = { 
    "DRUNK", 
    "BREAK_RULES", 
    "BREAKAGE", 
    "ROAD_CONDITIONS", 
    "OTHER" 
};
