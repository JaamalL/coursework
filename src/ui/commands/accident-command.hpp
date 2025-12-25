#pragma once

#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/accident-manager.hpp>

class AccidentCommand : public ICommand
{
private:
    AccidentManager& m_accidentManager;

public:
    AccidentCommand(AccidentManager& accidentManager);
public:
    void execute() override;

};
