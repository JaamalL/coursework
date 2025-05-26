#pragma once

#include <vector>
#include <string>

#include <src/ui/commands/i-command.hpp>

class HelpCommand : public ICommand
{
private:
    std::vector<std::string> m_commands;

public:
    HelpCommand(const std::vector<std::string>& commands);
public:
    void execute() override;

};
