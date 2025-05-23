#pragma once

#include <src/ui/commands/i-command.hpp>

class TheftCaseCommand : public ICommand
{
public:
    TheftCaseCommand();
public:
    void execute() override;

};
