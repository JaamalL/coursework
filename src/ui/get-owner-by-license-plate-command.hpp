#pragma once

#include <src/ui/i-command.hpp>
#include <src/domain-logic/vehicle-manager.hpp>

class GetOwnerByLicensePlateCommand : public ICommand
{
private:
    VehicleManager& m_manager;

public:
    GetOwnerByLicensePlateCommand(VehicleManager& manager);
    ~GetOwnerByLicensePlateCommand() = default;
public:
    void execute() override;

};
