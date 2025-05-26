#pragma once

#include <vector>

#include <src/entities/vehicle.hpp>

namespace Printer
{
    void printVehicle(const VehicleDTO& vehicle);
    void printVehicles(const std::vector<VehicleDTO>& vehicles);
};
