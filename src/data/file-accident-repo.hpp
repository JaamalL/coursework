#pragma once

#include <src/data/i-accident-repo.hpp>
#include <src/data/file-repo-base.hpp>

class FileAccidentRepo : public FileRepoBase<Accident>, public IAccidentRepo
{
public:
    FileAccidentRepo();
    ~FileAccidentRepo();
public:
    std::string entityToString(Accident* ent) override;
    Accident* stringToEntity(const std::string record) override;

    Accident* getById(const unsigned int id) override;
    const std::vector<Accident*>& getAll() override;

    void add(Accident* ent) override;

};
