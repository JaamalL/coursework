#pragma once

#include <src/ui/commands/i-command.hpp>

class VehicleCommand : public ICommand
{
public:
    VehicleCommand();
public:
    void execute() override;

};
