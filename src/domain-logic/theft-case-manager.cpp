#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <utility>

#include <src/domain-logic/theft-case-manager.hpp>
#include <vector>

TheftCaseManager::TheftCaseManager(ITheftCaseRepo& theftCaseRepo, IVehicleRepo& vehicleRepo)
:
    m_theftCaseRepo(theftCaseRepo),
    m_vehicleRepo(vehicleRepo)
{}

void TheftCaseManager::createTheftCase(const DateTime dateTime, const std::string location, 
    const std::string hackingMethod, const std::string vehicleLicensePlate)
{
    Vehicle* veh = m_vehicleRepo.getByLicensePlate(vehicleLicensePlate);

    if (veh == nullptr)
        throw std::runtime_error("Error: licnese plate not exists");

    m_theftCaseRepo.add(new TheftCase(dateTime, location, hackingMethod, veh->getId()));
}

std::vector<VehicleDTO> TheftCaseManager::getTheftVehicles() const
{
    std::vector<VehicleDTO> out;
    const std::vector<TheftCase*>& theftCases = m_theftCaseRepo.getAll();

    for (unsigned int i = 0; i < theftCases.size(); ++i)
    {
        if (theftCases[i]->getIsFound())
            continue;

        Vehicle* veh = m_vehicleRepo.getById(theftCases[i]->getVehicleId());

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

    return out;
}
float TheftCaseManager::getSearchEfficiency() const
{
    float found = 0;
    const std::vector<TheftCase*>& theftCases = m_theftCaseRepo.getAll();

    if (theftCases.size() == 0)
        return 0;

    for (unsigned int i = 0; i < theftCases.size(); ++i)
        if (theftCases[i]->getIsFound())
            found++;

    return found / (float)theftCases.size();
}
std::vector<TheftCaseDTO> TheftCaseManager::getByPeriod(const DateTime start, const DateTime end) const
{
    std::vector<TheftCaseDTO> out;
    const std::vector<TheftCase*>& theftCases = m_theftCaseRepo.getAll();

    for (unsigned int i = 0; i < theftCases.size(); ++i)
    {
        if (theftCases[i]->getDateTime() < start || theftCases[i]->getDateTime() > end)
            continue;

        out.push_back({
            theftCases[i]->getDateTime(),
            theftCases[i]->getLocation(),
            theftCases[i]->getHackingMethod(),
            m_vehicleRepo.getById(theftCases[i]->getVehicleId())->getLicensePlate(),
            theftCases[i]->getIsFound()
        });
    }

    return out;
}
std::unique_ptr<TheftCaseStatisticDTO> TheftCaseManager::getStatistic() const
{
    std::unique_ptr<TheftCaseStatisticDTO> out = std::make_unique<TheftCaseStatisticDTO>();
    const std::vector<TheftCase*>& theftCases = m_theftCaseRepo.getAll();
    std::unordered_map<std::string, unsigned int> brandStatMap;
    std::unordered_map<Vehicle::VehicleType, unsigned int> vehicleTypeStatMap;

    for (unsigned int i = 0; i < theftCases.size(); ++i)
    {
        Vehicle* veh = m_vehicleRepo.getById(theftCases[i]->getVehicleId());
        brandStatMap[veh->getBrand()]++;
        vehicleTypeStatMap[veh->getType()]++;
    }

    std::vector<std::pair<std::string, unsigned int>> brandStat(brandStatMap.begin(), 
        brandStatMap.end());
    
    std::sort(brandStat.begin(), brandStat.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        }
    );

    for (unsigned int i = 0; i < brandStat.size(); ++i)
        out->mostPopularBrands.push_back(brandStat[i].first);

    std::vector<std::pair<Vehicle::VehicleType, unsigned int>> vehicleTypeStat(vehicleTypeStatMap.begin(), 
        vehicleTypeStatMap.end());
    
    std::sort(vehicleTypeStat.begin(), vehicleTypeStat.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        }
    );

    for (unsigned int i = 0; i < vehicleTypeStat.size(); ++i)
        out->mostPopularVehicleTypes.push_back(Vehicle::vehicleTypeToString(vehicleTypeStat[i].first));

    return out;
}

void TheftCaseManager::setFound(const std::string licensePlate)
{
    const std::vector<TheftCase*>& theftCases = m_theftCaseRepo.getAll();
    TheftCase* theftCase = nullptr;

    for (unsigned int i = 0; i < theftCases.size(); ++i)
        if (m_vehicleRepo.getById(theftCases[i]->getVehicleId())->getLicensePlate() == licensePlate)
            theftCase = theftCases[i];
    
    if (theftCase == nullptr)
        throw std::runtime_error("Error: license plate not found");

    if (theftCase->getIsFound())
        throw std::runtime_error("Error: vehicle already found");

    theftCase->setFound();
}
