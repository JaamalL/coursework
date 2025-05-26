#pragma once

#include <src/data/i-owner-repo.hpp>
#include <src/data/file-repo-base.hpp>

class FileOwnerRepo : public FileRepoBase<Owner>, public IOwnerRepo
{
public:
    FileOwnerRepo();
    ~FileOwnerRepo();
public:
    std::string entityToString(Owner* ent) override;
    Owner* stringToEntity(const std::string record) override;

    Owner* getById(const unsigned int id) override;
    const std::vector<Owner*>& getAll() override;
    Owner* getByPhoneNumber(const std::string phoneNumber) override;

    void add(Owner* ent) override;

};
