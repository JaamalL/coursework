#include <src/entities/vehicle.hpp>

Vehicle::Vehicle(const std::string licensePlate, const VehicleType type, const std::string brand, 
    const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
    const std::string chassisSerialNumber, const std::string bodySerialNumber, const std::string color, 
    const bool isPassedInspection, const bool isAccident, const unsigned int ownerId)
:
    m_licensePlate(licensePlate),
    m_type(type),
    m_brand(brand),
    m_releaseYear(releaseYear),
    m_engineVolume(engineVolume),
    m_engineSerialNumber(engineSerialNumber),
    m_chassisSerialNumber(chassisSerialNumber),
    m_bodySerialNumber(bodySerialNumber),
    m_color(color),
    m_isPassedInspection(isPassedInspection),
    m_isAccident(isAccident),
    m_ownerId(ownerId)
{}
Vehicle::Vehicle(const unsigned int id, const std::string licensePlate, const VehicleType type, const std::string brand, 
    const unsigned int releaseYear, const float engineVolume, const std::string engineSerialNumber, 
    const std::string chassisSerialNumber, const std::string bodySerialNumber, const std::string color, 
    const bool isPassedInspection, const bool isAccident, const unsigned int ownerId)
:
    Entity(id),
    m_licensePlate(licensePlate),
    m_type(type),
    m_brand(brand),
    m_releaseYear(releaseYear),
    m_engineVolume(engineVolume),
    m_engineSerialNumber(engineSerialNumber),
    m_chassisSerialNumber(chassisSerialNumber),
    m_bodySerialNumber(bodySerialNumber),
    m_color(color),
    m_isPassedInspection(isPassedInspection),
    m_isAccident(isAccident),
    m_ownerId(ownerId)
{}

std::string          Vehicle::getLicensePlate() const { return m_licensePlate; }
Vehicle::VehicleType Vehicle::getType() const { return m_type; }
std::string          Vehicle::getBrand() const { return m_brand; }
unsigned int         Vehicle::getReleaseYear() const { return m_releaseYear; }
float                Vehicle::getEngineVolume() const { return m_engineVolume; }
std::string          Vehicle::getEngineSerialNumber() const { return m_engineSerialNumber; }
std::string          Vehicle::getChassisSerialNumber() const { return m_chassisSerialNumber; }
std::string          Vehicle::getBodySerialNumber() const { return m_bodySerialNumber; }
std::string          Vehicle::getColor() const { return m_color; }
bool                 Vehicle::getIsPassedInspection() const { return m_isPassedInspection; }
bool                 Vehicle::getIsAccident() const { return m_isAccident; }
unsigned int         Vehicle::getOwnerId() const { return m_ownerId; }

void Vehicle::setIsAccident(const bool isAccident) { m_isAccident = isAccident; }

std::string Vehicle::vehicleTypeToString(VehicleType type) { return m_vehicleTypeStr[(unsigned int)type]; }
bool Vehicle::isValidVehicleType(const unsigned int type) 
{ 
    return type <= (unsigned int)Vehicle::VehicleType::BUS_MINI; 
}

std::string Vehicle::m_vehicleTypeStr[] = {
    "CAR_PASSENGER", 
    "CAR_TRUCK",
    "TRAILER",
    "SEMI_TRAILER",
    "MOTO",
    "TRACTOR",
    "BUS",
    "BUS_MINI"
};
