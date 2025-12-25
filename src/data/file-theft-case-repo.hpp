#pragma once

#include <src/data/i-theft-case-repo.hpp>
#include <src/data/file-repo-base.hpp>

class FileTheftCaseRepo : public FileRepoBase<TheftCase>, public ITheftCaseRepo
{
public:
    FileTheftCaseRepo();
    ~FileTheftCaseRepo();
public:
    std::string entityToString(TheftCase* ent) override;
    TheftCase* stringToEntity(const std::string record) override;

    TheftCase* getById(const unsigned int id) override;
    const std::vector<TheftCase*>& getAll() override;

    void add(TheftCase* ent) override;

};
