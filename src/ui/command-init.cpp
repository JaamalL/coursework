#include <src/ui/command-init.hpp>
#include <src/ui/commands/accident-command.hpp>
#include <src/ui/commands/exit-command.hpp>
#include <src/ui/commands/help-command.hpp>
#include <src/ui/commands/organization-command.hpp>
#include <src/ui/commands/owner-command.hpp>
#include <src/ui/commands/theft-case-command.hpp>
#include <src/ui/commands/vehicle-command.hpp>

CommandInit::CommandInit(AccidentManager& accidentManager, OrganizationManager& organizationManager, 
    OwnerManager& ownerManager, TheftCaseManager& theftCaseManager, 
    VehicleManager& vehicleManager)
{
    m_commands["accident"] = new AccidentCommand(accidentManager);
    m_commands["organization"] = new OrganizationCommand(organizationManager);
    m_commands["owner"] = new OwnerCommand(ownerManager);
    m_commands["theft-case"] = new TheftCaseCommand(theftCaseManager);
    m_commands["vehicle"] = new VehicleCommand(vehicleManager);
    m_commands["help"] = new HelpCommand(getCommandNames());
    m_commands["exit"] = new ExitCommand();
}

ICommand* CommandInit::getCommand(const std::string commandName) const
{
    auto command = m_commands.find(commandName);

    if (command == m_commands.end())
        return nullptr;

    return command->second;
}
std::vector<std::string> CommandInit::getCommandNames() const
{
    std::vector<std::string> out;

    for (auto& it : m_commands)
        out.push_back(it.first);

    return out;
}
