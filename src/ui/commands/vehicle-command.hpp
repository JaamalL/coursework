#pragma once

#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/vehicle-manager.hpp>

class VehicleCommand : public ICommand
{
private:
    VehicleManager& m_vehicleManager;

public:
    VehicleCommand(VehicleManager& vehicleManager);
public:
    void execute() override;

};
