#include <src/data/file-organization-repo.hpp>
#include <src/helpers/string-util.hpp>

FileOrganizationRepo::FileOrganizationRepo()
:
    FileRepoBase("organization.dump")
{
    load();
}
FileOrganizationRepo::~FileOrganizationRepo()
{
    save();
}

std::string FileOrganizationRepo::entityToString(Organization* ent)
{
    return StringUtil::join({
        std::to_string(ent->getId()),
        ent->getOrganizationName(),
        ent->getAddress(),
        ent->getManagerFullName(),
        StringUtil::join(ent->getVehicleRecordIds())
    }, FILE_SEPARATOR);
}
Organization* FileOrganizationRepo::stringToEntity(const std::string record)
{
    std::vector<std::string> entFields = StringUtil::splitString(record, FILE_SEPARATOR);
    std::vector<unsigned int> vehicleRecordIds = StringUtil::splitNumber(entFields[4]);
    
    return new Organization(std::stoul(entFields[0]), entFields[1], 
        entFields[2], entFields[3], vehicleRecordIds);
}

Organization* FileOrganizationRepo::getById(const unsigned int id)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getId() == id)
            return m_entities[i];
    
    return nullptr;
}
const std::vector<Organization*>& FileOrganizationRepo::getAll()
{
    return m_entities;
}
Organization* FileOrganizationRepo::getByName(const std::string name)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
        if (m_entities[i]->getOrganizationName() == name)
            return m_entities[i];
    
    return nullptr;
}

void FileOrganizationRepo::add(Organization* ent)
{
    if (ent != nullptr)
        m_entities.push_back(ent);
}
