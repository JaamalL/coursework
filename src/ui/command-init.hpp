#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/accident-manager.hpp>
#include <src/domain-logic/organization-manager.hpp>
#include <src/domain-logic/owner-manager.hpp>
#include <src/domain-logic/theft-case-manager.hpp>
#include <src/domain-logic/vehicle-manager.hpp>

class CommandInit
{
private:
    AccidentManager& m_accidentManager;
    OrganizationManager& m_organizationManager;
    OwnerManager& m_ownerManager;
    TheftCaseManager& m_theftCaseManager;
    VehicleManager& m_vehicleManager;
    std::unordered_map<std::string, ICommand*> m_commands;

public:
    CommandInit(AccidentManager& accidentManager, OrganizationManager& organizationManager, 
        OwnerManager& ownerManager, TheftCaseManager& theftCaseManager, 
        VehicleManager& vehicleManager);
public:
    ICommand* getCommand(const std::string commandName) const;
    std::vector<std::string> getCommandNames() const;

};
