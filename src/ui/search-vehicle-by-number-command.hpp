#pragma once

#include <src/ui/i-command.hpp>
#include <src/domain-logic/vehicle-manager.hpp>

class SearchVehicleByNumberCommand : public ICommand
{
private:
    VehicleManager& m_manager;

public:
    SearchVehicleByNumberCommand(VehicleManager& manager);
    ~SearchVehicleByNumberCommand() = default;
public:
    void execute() override;

};
