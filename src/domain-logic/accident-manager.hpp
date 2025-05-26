#pragma once

#include <memory>

#include <src/entities/accident.hpp>
#include <src/data/i-accident-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>

class AccidentManager
{
private:
    IAccidentRepo& m_accidentRepo;
    IVehicleRepo& m_vehicleRepo;

public:
    AccidentManager(IAccidentRepo& accidentRepo, IVehicleRepo& vehicleRepo);
public:
    void createAccident(const DateTime dateTime, const Accident::AccidentType accidentType, 
        const std::string location, std::vector<std::string>& participantsVehicles, 
        const std::string description, const unsigned int injuredCount, const float damageCost, 
        const Accident::CauseType cause, const std::string roadConditions, 
        std::vector<std::string>& escapedVehicles);

    std::unique_ptr<AccidentStatisticDTO> getStatisticByTypeAndPeriod(
        const Accident::AccidentType type, const DateTime start, const DateTime end) const;
    std::unique_ptr<AccidentAnalysisDTO> getAnalysis() const;
    std::unique_ptr<AccidentDrunkDTO> getDrunkStatistic() const;
    std::vector<VehicleDTO> getEscapedVehicles() const;

};
