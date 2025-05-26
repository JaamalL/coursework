#pragma once

#include <vector>
#include <memory>

#include <src/entities/vehicle.hpp>
#include <src/entities/theft-case.hpp>
#include <src/data/i-theft-case-repo.hpp>
#include <src/data/i-vehicle-repo.hpp>

class TheftCaseManager
{
private:
    ITheftCaseRepo& m_theftCaseRepo;
    IVehicleRepo& m_vehicleRepo;

public:
    TheftCaseManager(ITheftCaseRepo& theftCaseRepo, IVehicleRepo& vehicleRepo);
public:
    void createTheftCase(const DateTime dateTime, const std::string location, 
        const std::string hackingMethod, const std::string vehicleLicensePlate);

    std::vector<VehicleDTO> getTheftVehicles() const;
    float getSearchEfficiency() const;
    std::vector<TheftCaseDTO> getByPeriod(const DateTime start, const DateTime end) const;
    std::unique_ptr<TheftCaseStatisticDTO> getStatistic() const;
    
    void setFound(const std::string licensePlate);

};
