#pragma once

#include <vector>

#include <src/entities/vehicle.hpp>

class IVehicleRepository
{
public:
    virtual ~IVehicleRepository() = default;
public:
    virtual std::vector<Vehicle*> getVehicles() = 0;

    virtual void setVehicles(const std::vector<Vehicle*>& vehicles) = 0;

};
