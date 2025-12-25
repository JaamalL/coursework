#include <src/data/file-accident-repo.hpp>
#include <src/helpers/string-util.hpp>

FileAccidentRepo::FileAccidentRepo()
:
    FileRepoBase("accident.dump")
{
    load();
}
FileAccidentRepo::~FileAccidentRepo()
{
    save();
}

std::string FileAccidentRepo::entityToString(Accident* ent)
{
    return StringUtil::join({ 
        std::to_string(ent->getId()),
        ent->getDateTime().toSring(),
        std::to_string((unsigned int)ent->getAccidentType()),
        ent->getLocation(),
        StringUtil::join(ent->getParticipantVehicleIds()),
        ent->getDescription(),
        std::to_string(ent->getInjuredCount()),
        std::to_string(ent->getDamageCost()),
        std::to_string((unsigned int)ent->getCause()),
        ent->getRoadConditions(),
        StringUtil::join(ent->getEscapedVehicleIds())
    }, FILE_SEPARATOR);
}
Accident* FileAccidentRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);
    std::vector<unsigned int> participantsVehicleIds = StringUtil::splitNumber(entFields[4]);
    std::vector<unsigned int> escapedVehicleIds = StringUtil::splitNumber(entFields[10]);

    return new Accident(
        std::stoul(entFields[0]), 
        entFields[1], 
        (Accident::AccidentType)std::stoul(entFields[2]), 
        entFields[3], 
        participantsVehicleIds, 
        entFields[5], 
        std::stoul(entFields[6]), 
        std::stof(entFields[7]), 
        (Accident::CauseType)std::stoul(entFields[8]), 
        entFields[9], 
        escapedVehicleIds
    );
}

Accident* FileAccidentRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];
    
    return nullptr;
}
const std::vector<Accident*>& FileAccidentRepo::getAll()
{
    return m_entities;
}

void FileAccidentRepo::add(Accident* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
