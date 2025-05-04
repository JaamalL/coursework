#pragma once

#include <src/ui/i-command.hpp>
#include <src/domain-logic/vehicle-manager.hpp>

class GetVehicleByLicensePlateCommand : public ICommand
{
private:
    VehicleManager& m_manager;

public:
    GetVehicleByLicensePlateCommand(VehicleManager& manager);
    ~GetVehicleByLicensePlateCommand() = default;
public:
    void execute() override;

};
