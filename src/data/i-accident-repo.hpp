#pragma once

#include <src/entities/accident.hpp>

class IAccidentRepo
{
public:
    virtual ~IAccidentRepo() = default;
public:
    virtual Accident* getById(const unsigned int id) = 0;
    virtual const std::vector<Accident*>& getAll() = 0;

    virtual void add(Accident* ent) = 0;
};
