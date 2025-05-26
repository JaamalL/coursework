#pragma once

#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/theft-case-manager.hpp>

class TheftCaseCommand : public ICommand
{
private:
    TheftCaseManager& m_theftCaseManager;

public:
    TheftCaseCommand(TheftCaseManager& theftCaseManager);
public:
    void execute() override;

};
