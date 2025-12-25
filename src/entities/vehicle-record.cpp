#include <src/entities/vehicle-record.hpp>

VehicleRecord::VehicleRecord(const DateTime dateTime, const unsigned int vehicleId)
:
    m_dateTime(dateTime),
    m_vehicleId(vehicleId)
{}
VehicleRecord::VehicleRecord(const unsigned int id, const DateTime dateTime, const unsigned int vehicleId)
:
    m_dateTime(dateTime),
    m_vehicleId(vehicleId)
{}

DateTime     VehicleRecord::getDateTime() const { return m_dateTime; }
unsigned int VehicleRecord::getVehicleId() const { return m_vehicleId; }
