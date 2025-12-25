#pragma once

#include <src/ui/commands/i-command.hpp>

class ExitCommand : public ICommand
{
public:
    ExitCommand() = default;
public:
    void execute() override;

};
