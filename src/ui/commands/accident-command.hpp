#pragma once

#include <src/ui/commands/i-command.hpp>

class AccidentCommand : public ICommand
{
public:
    AccidentCommand();
public:
    void execute() override;

};
