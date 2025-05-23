#pragma once

#include <src/ui//commands/i-command.hpp>

class OrganizationCommand : public ICommand
{
public:
    OrganizationCommand();
public:
    void execute() override;

};
