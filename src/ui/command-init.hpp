#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include <src/ui/commands/i-command.hpp>

class CommandInit
{
private:
    std::unordered_map<std::string, ICommand*> m_commands;

public:
    CommandInit();
public:
    ICommand* getCommand(const std::string commandName) const;
    std::vector<std::string> getCommandNames() const;

};
