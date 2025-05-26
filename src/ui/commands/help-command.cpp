#include <iostream>

#include <src/ui/commands/help-command.hpp>

HelpCommand::HelpCommand(const std::vector<std::string>& commands)
:
    m_commands(commands)
{}

void HelpCommand::execute()
{
    std::cout << "======================================\n";
    std::cout << "Available commands: \n";
    for (unsigned int i = 0; i < m_commands.size(); ++i)
        std::cout << '\t' << std::to_string(i + 1) << " - " << m_commands[i] << std::endl;
    
    std::cout << "======================================\n";
}
