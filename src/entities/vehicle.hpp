#pragma once

#include <string>
#include <vector>
#include <ctime>

#include <src/entities/owner.hpp>
#include <src/entities/entity.hpp>

class Vehicle : Entity<Vehicle>
{
public:
    enum VehicleType
    {

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
    unsigned int m_ownerId;

public:
    Vehicle(const std::string licensePlate, const VehicleType type, const std::string brand, 
        const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
        const std::string chassisSerialNamber, const std::string bodySerialNumber, const std::string color, const unsigned int ownerId);
    ~Vehicle() = default;
public:
    std::string  getLicensePlate() const;
    VehicleType  getType() const;
    std::string  getBrand() const;
    unsigned int getReleaseYear() const;
    float        getEngineVolume() const;
    std::string  getEngineSerialNumber() const;
    std::string  getChassisSerialNamber() const;
    std::string  getBodySerialNumber() const;
    std::string  getColor() const;
    unsigned int getOwnerId() const;
    
    void setLicensePlate(const std::string licensePlate);
    void setColor(const std::string color);
    void setOwner(const unsigned int ownerId);
    
};
