#pragma once

#include <vector>

#include <src/entities/vehicle-record.hpp>

class IVehicleRecordRepo
{
public:
    virtual ~IVehicleRecordRepo() = default;
public:
    virtual VehicleRecord* getById(const unsigned int id) = 0;
    virtual const std::vector<VehicleRecord*>& getAll() = 0;

    virtual void add(VehicleRecord* ent) = 0;   

};
