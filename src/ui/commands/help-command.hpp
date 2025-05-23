#pragma once

#include <src/ui/commands/i-command.hpp>

class HelpCommand : public ICommand
{
public:
    HelpCommand();
public:
    void execute() override;

};
