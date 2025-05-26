#pragma once

#include <vector>

#include <src/entities/organization.hpp>

class IOrganizationRepo
{
public:
    virtual ~IOrganizationRepo() = default;
public:
    virtual Organization* getById(const unsigned int id) = 0;
    virtual const std::vector<Organization*>& getAll() = 0;
    virtual Organization* getByName(const std::string name) = 0;

    virtual void add(Organization* ent) = 0;

};
