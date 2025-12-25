#pragma once

#include <src/entities/theft-case.hpp>

class ITheftCaseRepo
{
public:
    virtual ~ITheftCaseRepo() = default;
public:
    virtual TheftCase* getById(const unsigned int id) = 0;
    virtual const std::vector<TheftCase*>& getAll() = 0;

    virtual void add(TheftCase* ent) = 0;
};
