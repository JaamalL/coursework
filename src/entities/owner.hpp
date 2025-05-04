#pragma once

#include <vector>

#include <src/entities/vehicle.hpp>


class Owner
{
public:
    enum OwnerType
    {
        INDIVIDUAL,
        ORGANIZATION
    };

protected:
    OwnerType m_ownerType;

public:
    Owner(const OwnerType ownerType);
    ~Owner() = default;
public:
    OwnerType getOwnerType() const;

};
