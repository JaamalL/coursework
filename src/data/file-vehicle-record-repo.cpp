#include <src/data/file-vehicle-record-repo.hpp>
#include <src/helpers/string-util.hpp>

FileVehicleRecordRepo::FileVehicleRecordRepo()
:
    FileRepoBase("vehicle-record.dump")
{
    load();
}
FileVehicleRecordRepo::~FileVehicleRecordRepo()
{
    save();
}

std::string FileVehicleRecordRepo::entityToString(VehicleRecord* ent)
{
    return StringUtil::join({ 
        std::to_string(ent->getId()),
        ent->getDateTime().toSring(),
        std::to_string(ent->getVehicleId())
    }, FILE_SEPARATOR);
}
VehicleRecord* FileVehicleRecordRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);

    return new VehicleRecord(std::stoul(entFields[0]), entFields[1],
         std::stoul(entFields[2]));
}

VehicleRecord* FileVehicleRecordRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];

    return nullptr;
}
const std::vector<VehicleRecord*>& FileVehicleRecordRepo::getAll()
{
    return m_entities;
}

void FileVehicleRecordRepo::add(VehicleRecord* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
