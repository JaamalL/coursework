#include <string>

#include "src/entities/vehicle.hpp"
#include <src/data/file-vehicle-repo.hpp>
#include <src/helpers/string-util.hpp>

FileVehicleRepo::FileVehicleRepo()
:
    FileRepoBase("vehicle.dump")
{
    load();
}
FileVehicleRepo::~FileVehicleRepo()
{
    save();
}

std::string FileVehicleRepo::entityToString(Vehicle* ent)
{
    return StringUtil::join({ 
        std::to_string(ent->getId()),
        ent->getLicensePlate(),
        std::to_string((unsigned int)ent->getType()),
        ent->getBrand(), 
        std::to_string(ent->getReleaseYear()),
        std::to_string(ent->getEngineVolume()),
        ent->getEngineSerialNumber(),
        ent->getChassisSerialNumber(),
        ent->getBodySerialNumber(),
        ent->getColor(),
        std::to_string(ent->getIsPassedInspection()),
        std::to_string(ent->getIsAccident()),
        std::to_string(ent->getOwnerId())
    }, FILE_SEPARATOR);
}
Vehicle* FileVehicleRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);
    
    return new Vehicle(std::stoul(entFields[0]), entFields[1], 
        (Vehicle::VehicleType)std::stoul(entFields[2]), entFields[3], 
        std::stoul(entFields[4]), std::stof(entFields[5]), 
        entFields[6], entFields[7], entFields[8], 
        entFields[9], (bool)std::stoul(entFields[10]), 
        (bool)std::stoul(entFields[11]), std::stoul(entFields[12]));
}

Vehicle* FileVehicleRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];
    
    return nullptr;
}
const std::vector<Vehicle*>& FileVehicleRepo::getAll()
{
    return m_entities;
}
Vehicle* FileVehicleRepo::getByLicensePlate(const std::string licensePlate)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getLicensePlate() == licensePlate)
            return m_entities[i];
    
    return nullptr;
}

void FileVehicleRepo::add(Vehicle* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
