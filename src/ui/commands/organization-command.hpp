#pragma once

#include <src/entities/organization.hpp>
#include <src/ui/commands/i-command.hpp>
#include <src/domain-logic/organization-manager.hpp>

class OrganizationCommand : public ICommand
{
private:
    OrganizationManager& m_organizationManager;

    static void printOrganizations(const std::vector<OrganizationDTO>& organizations);

public:
    OrganizationCommand(OrganizationManager& organizationManager);
public:
    void execute() override;

};
