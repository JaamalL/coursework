#pragma once

#include <src/data/file-repo-base.hpp>
#include <src/data/i-vehicle-repo.hpp>
#include <src/entities/vehicle.hpp>

class FileVehicleRepo : public FileRepoBase<Vehicle>, public IVehicleRepo
{
public:
    FileVehicleRepo();
    ~FileVehicleRepo();
public:
    std::string entityToString(Vehicle* ent) override;
    Vehicle* stringToEntity(const std::string record) override;

    Vehicle* getById(const unsigned int id) override;
    const std::vector<Vehicle*>& getAll() override;
    Vehicle* getByLicensePlate(const std::string licensePlate) override;

    void add(Vehicle* ent) override;

};
