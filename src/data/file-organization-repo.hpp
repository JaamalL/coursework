#pragma once

#include <src/data/file-repo-base.hpp>
#include <src/data/i-organization-repo.hpp>

class FileOrganizationRepo : public FileRepoBase<Organization>, public IOrganizationRepo
{
public:
    FileOrganizationRepo();
    ~FileOrganizationRepo();
public:
    std::string entityToString(Organization* ent) override;
    Organization* stringToEntity(const std::string record) override;

    Organization* getById(const unsigned int id) override;
    const std::vector<Organization*>& getAll() override;
    Organization* getByName(const std::string name) override;

    void add(Organization* ent) override;

};
