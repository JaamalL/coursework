#pragma once

#include <src/entities/entity.hpp>
#include <src/helpers/date-time.hpp>

struct VehicleRecordDTO
{
    DateTime dateTime;
    std::string licensePlate;
};

class VehicleRecord : public Entity<VehicleRecord>
{
private:
    DateTime m_dateTime;
    unsigned int m_vehicleId;

public:
    VehicleRecord(const DateTime dateTime, const unsigned int vehicleId);
    VehicleRecord(const unsigned int id, const DateTime dateTime, const unsigned int vehicleId);
public:
    DateTime     getDateTime() const;
    unsigned int getVehicleId() const;

};
