#pragma once

#include <src/ui/commands/i-command.hpp>

class OwnerCommand : public ICommand
{
public:
    OwnerCommand();
public:
    void execute() override;

};
