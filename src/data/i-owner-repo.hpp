#pragma once

#include <vector>

#include <src/entities/owner.hpp>

class IOwnerRepo
{
public:
    virtual ~IOwnerRepo() = default;
public:
    virtual Owner* getById(const unsigned int id) = 0;
    virtual const std::vector<Owner*>& getAll() = 0;
    virtual Owner* getByPhoneNumber(const std::string phoneNumber) = 0;

    virtual void add(Owner* ent) = 0;

};
