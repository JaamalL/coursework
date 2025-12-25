#include <src/data/file-owner-repo.hpp>
#include <src/helpers/string-util.hpp>

FileOwnerRepo::FileOwnerRepo()
:
    FileRepoBase("owner.dump")
{
    load();
}
FileOwnerRepo::~FileOwnerRepo()
{
    save();
}

std::string FileOwnerRepo::entityToString(Owner* ent)
{
    return StringUtil::join({ 
        std::to_string(ent->getId()),
        ent->getPhoneNumber(),
        ent->getSurname(),
        ent->getName(),
        ent->getPatronymic(),
        ent->getAddress()
    }, FILE_SEPARATOR);
}
Owner* FileOwnerRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);

    return new Owner(std::stoul(entFields[0]), entFields[1], 
        entFields[2], entFields[3], entFields[4], entFields[5]);
}

Owner* FileOwnerRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];

    return nullptr;
}
const std::vector<Owner*>& FileOwnerRepo::getAll()
{
    return m_entities;
}
Owner* FileOwnerRepo::getByPhoneNumber(const std::string phoneNumber)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getPhoneNumber() == phoneNumber)
            return m_entities[i];

    return nullptr;
}

void FileOwnerRepo::add(Owner* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
