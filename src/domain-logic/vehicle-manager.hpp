#pragma once

#include <src/entities/vehicle.hpp>
#include <src/data/i-vehicle-repository.hpp>

class VehicleManager
{
private:
    std::vector<Vehicle*> m_vehicles;

public:
    VehicleManager(IVehicleRepository& repository);
    ~VehicleManager();
public:

};
