#pragma once

#include <string>
#include <ctime>

#include <src/entities/owner.hpp>
#include <src/entities/entity.hpp>

struct VehicleDTO
{
    std::string licensePlate;
    std::string type;
    std::string brand;
    unsigned int releaseYear;
    float engineVolume;
    std::string engineSerialNumber;
    std::string chassisSerialNumber;
    std::string bodySerialNumber;
    std::string color;
    bool isPassedInspection;
    bool isAccident;
};

class Vehicle : public Entity<Vehicle>
{
public:
    enum class VehicleType 
    {
        CAR_PASSENGER, 
        CAR_TRUCK,
        TRAILER,
        SEMI_TRAILER,
        MOTO,
        TRACTOR,
        BUS,
        BUS_MINI
    };

private:
    std::string m_licensePlate;
    VehicleType m_type;
    std::string m_brand;
    unsigned int m_releaseYear;
    float m_engineVolume;
    std::string m_engineSerialNumber;
    std::string m_chassisSerialNumber;
    std::string m_bodySerialNumber;
    std::string m_color;
    bool m_isPassedInspection;
    bool m_isAccident;
    unsigned int m_ownerId;

    static std::string m_vehicleTypeStr[];

public:
    Vehicle(const std::string licensePlate, const VehicleType type, const std::string brand, 
        const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
        const std::string chassisSerialNumber, const std::string bodySerialNumber, const std::string color, 
        const bool isPassedInspection, const bool isAccident, const unsigned int ownerId);
    Vehicle(const unsigned int id, const std::string licensePlate, const VehicleType type, const std::string brand, 
        const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
        const std::string chassisSerialNamber, const std::string bodySerialNumber, const std::string color, 
        const bool isPassedInspection, const bool isAccident, const unsigned int ownerId);
public:
    std::string  getLicensePlate() const;
    VehicleType  getType() const;
    std::string  getBrand() const;
    unsigned int getReleaseYear() const;
    float        getEngineVolume() const;
    std::string  getEngineSerialNumber() const;
    std::string  getChassisSerialNumber() const;
    std::string  getBodySerialNumber() const;
    std::string  getColor() const;
    bool         getIsPassedInspection() const;
    bool         getIsAccident() const;
    unsigned int getOwnerId() const;

    void setIsAccident(const bool isAccident);

    static std::string vehicleTypeToString(VehicleType type);
    static bool isValidVehicleType(const unsigned int type);
    
};
