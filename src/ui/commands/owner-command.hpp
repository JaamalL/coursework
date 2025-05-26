#pragma once

#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/owner-manager.hpp>

class OwnerCommand : public ICommand
{
private:
    OwnerManager& m_ownerManager;

    static void printOwner(const OwnerDTO& owner);

public:
    OwnerCommand(OwnerManager& ownerManager);
public:
    void execute() override;

};
