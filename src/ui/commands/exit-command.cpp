#include <stdexcept>

#include <src/ui/commands/exit-command.hpp>

void ExitCommand::execute()
{
    throw std::runtime_error("Exit");
}
