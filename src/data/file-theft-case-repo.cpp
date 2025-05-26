#include <src/data/file-theft-case-repo.hpp>
#include <src/helpers/string-util.hpp>

FileTheftCaseRepo::FileTheftCaseRepo()
:
    FileRepoBase("theft-case.dump")
{
    load();
}
FileTheftCaseRepo::~FileTheftCaseRepo()
{
    save();
}

std::string FileTheftCaseRepo::entityToString(TheftCase* ent)
{
    return StringUtil::join({ 
        std::to_string(ent->getId()),
        ent->getDateTime().toSring(),
        ent->getLocation(),
        std::to_string(ent->getVehicleId()),
        std::to_string(ent->getIsFound())
    }, FILE_SEPARATOR);
}
TheftCase* FileTheftCaseRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);

    return new TheftCase(std::stoul(entFields[0]), entFields[1], 
        entFields[2], entFields[3], std::stoul(entFields[4]));
}

TheftCase* FileTheftCaseRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];

    return nullptr;
}
const std::vector<TheftCase*>& FileTheftCaseRepo::getAll()
{
    return m_entities;
}

void FileTheftCaseRepo::add(TheftCase* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
