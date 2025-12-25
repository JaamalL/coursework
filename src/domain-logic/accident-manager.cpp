#include "src/data/i-vehicle-repo.hpp"
#include "src/entities/vehicle.hpp"
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <src/domain-logic/accident-manager.hpp>

AccidentManager::AccidentManager(IAccidentRepo& accidentRepo, IVehicleRepo& vehicleRepo)
:
    m_accidentRepo(accidentRepo),
    m_vehicleRepo(vehicleRepo)
{}

void AccidentManager::createAccident(const DateTime dateTime, const Accident::AccidentType accidentType, 
    const std::string location, std::vector<std::string>& participantsVehicles, 
    const std::string description, const unsigned int injuredCount, const float damageCost, 
    const Accident::CauseType cause, const std::string roadConditions, 
    std::vector<std::string>& escapedVehicles)
{
    std::vector<unsigned int> participantsVehicleIds;
    std::vector<Vehicle*> participantsVehicleEnts;
    for (unsigned int i = 0; i < participantsVehicles.size(); ++i)
    {
        Vehicle* veh = m_vehicleRepo.getByLicensePlate(participantsVehicles[i]);

        if (veh == nullptr)
            throw std::runtime_error("Error: license plate not exists");

        participantsVehicleIds.push_back(veh->getId());
        participantsVehicleEnts.push_back(veh);
    }

    std::vector<unsigned int> escapedVehicleIds;
    std::vector<Vehicle*> escapedVehicleEnts;
    for (unsigned int i = 0; i < escapedVehicles.size(); ++i)
    {
        Vehicle* veh = m_vehicleRepo.getByLicensePlate(escapedVehicles[i]);

        if (veh == nullptr)
            throw std::runtime_error("Error: license plate not exists");

        escapedVehicleIds.push_back(veh->getId());
        escapedVehicleEnts.push_back(veh);
    }

    for (unsigned int i = 0; i < participantsVehicleEnts.size(); ++i)
        participantsVehicleEnts[i]->setIsAccident(true);

    for (unsigned int i = 0; i < escapedVehicleEnts.size(); ++i)
        escapedVehicleEnts[i]->setIsAccident(true);

    m_accidentRepo.add(new Accident(dateTime, accidentType, location, participantsVehicleIds, 
        description, injuredCount, damageCost, cause, roadConditions, escapedVehicleIds));
}

std::unique_ptr<AccidentStatisticDTO> AccidentManager::getStatisticByTypeAndPeriod(
    const Accident::AccidentType type, const DateTime start, const DateTime end) const
{
    std::unique_ptr<AccidentStatisticDTO> out = std::make_unique<AccidentStatisticDTO>();
    const std::vector<Accident*>& accidents = m_accidentRepo.getAll();

    for (unsigned int i = 0; i < accidents.size(); ++i)
    {
        if (accidents[i]->getAccidentType() != type || accidents[i]->getDateTime() < start || 
            accidents[i]->getDateTime() > end)
            continue;
        
        out->total++;
        out->totalInjuredCount += accidents[i]->getInjuredCount();
        out->totalParticipantVehicles += accidents[i]->getParticipantVehicleIds().size();
        out->totalEscapedVehicles += accidents[i]->getEscapedVehicleIds().size();
        out->totalDamageCost += accidents[i]->getDamageCost();
    }

    return out;
}
std::unique_ptr<AccidentAnalysisDTO>  AccidentManager::getAnalysis() const
{
    std::unique_ptr<AccidentAnalysisDTO> out = std::make_unique<AccidentAnalysisDTO>();
    const std::vector<Accident*>& accidents = m_accidentRepo.getAll();
    std::unordered_map<std::string, unsigned int> locationStatMap;
    std::unordered_map<Accident::CauseType, unsigned int> causeStatMap;

    for (unsigned int i = 0; i < accidents.size(); ++i)
    {
        locationStatMap[accidents[i]->getLocation()]++;
        causeStatMap[accidents[i]->getCause()]++;
    }

    std::vector<std::pair<std::string, unsigned int>> locationStat(locationStatMap.begin(), 
        locationStatMap.end());
    
    std::sort(locationStat.begin(), locationStat.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        }
    );

    for (unsigned int i = 0; i < locationStat.size(); ++i)
        out->mostDanagerousLocations.push_back(locationStat[i].first);

    std::vector<std::pair<Accident::CauseType, unsigned int>> causeStat(causeStatMap.begin(), 
        causeStatMap.end());
    
    out->mostPopularCouse = Accident::causeTypeToString(std::max_element(causeStat.begin(), 
        causeStat.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        }
    )->first);

    return out;
}
std::unique_ptr<AccidentDrunkDTO>     AccidentManager::getDrunkStatistic() const
{
    std::unique_ptr<AccidentDrunkDTO> out = std::make_unique<AccidentDrunkDTO>();
    const std::vector<Accident*>& accidents = m_accidentRepo.getAll();

    if (accidents.size() == 0)
        return out;

    for (unsigned int i = 0; i < accidents.size(); ++i)
        if (accidents[i]->getCause() == Accident::CauseType::DRUNK)
            out->total++;
    
    out->part = (float)out->total / (float)accidents.size();

    return out;
}
std::vector<VehicleDTO>               AccidentManager::getEscapedVehicles() const
{
    std::vector<VehicleDTO> out;
    const std::vector<Accident*>& accidents = m_accidentRepo.getAll();

    for (unsigned int i = 0; i < accidents.size(); ++i)
    {
        const std::vector<unsigned int>& escapedVehicleIds = accidents[i]->getEscapedVehicleIds();
        for (unsigned int j = 0; j < escapedVehicleIds.size(); ++j)
        {
            Vehicle* veh = m_vehicleRepo.getById(escapedVehicleIds[j]);

            out.push_back({
                veh->getLicensePlate(),
                Vehicle::vehicleTypeToString(veh->getType()),
                veh->getBrand(),
                veh->getReleaseYear(),
                veh->getEngineVolume(),
                veh->getEngineSerialNumber(),
                veh->getChassisSerialNumber(),
                veh->getBodySerialNumber(),
                veh->getColor(),
                veh->getIsPassedInspection(),
                veh->getIsAccident()
            });
        }
    }

    return out;
}
