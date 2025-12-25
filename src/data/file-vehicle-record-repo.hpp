#pragma once

#include <src/data/i-vehicle-record-repo.hpp>
#include <src/data/file-repo-base.hpp>

class FileVehicleRecordRepo : public FileRepoBase<VehicleRecord>, public IVehicleRecordRepo
{
public:
    FileVehicleRecordRepo();
    ~FileVehicleRecordRepo();
public:
    std::string entityToString(VehicleRecord* ent) override;
    VehicleRecord* stringToEntity(const std::string record) override;

    VehicleRecord* getById(const unsigned int id) override;
    const std::vector<VehicleRecord*>& getAll() override;

    void add(VehicleRecord* ent) override;

};
