#pragma once

#include <vector>

#include <src/entities/vehicle.hpp>

class IVehicleRepo
{
public:
    virtual ~IVehicleRepo() = default;
public:
    virtual Vehicle* getById(const unsigned int id) = 0;
    virtual const std::vector<Vehicle*>& getAll() = 0;
    virtual Vehicle* getByLicensePlate(const std::string licensePlate) = 0;

    virtual void add(Vehicle* ent) = 0;

};
