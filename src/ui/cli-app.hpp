#pragma once

#include <memory>

#include <src/domain-logic/accident-manager.hpp>
#include <src/domain-logic/organization-manager.hpp>
#include <src/domain-logic/owner-manager.hpp>
#include <src/domain-logic/theft-case-manager.hpp>
#include <src/domain-logic/vehicle-manager.hpp>
#include <src/ui/command-init.hpp>

class CLIApp
{
private:
    std::unique_ptr<IAccidentRepo> m_accidentRepo;
    std::unique_ptr<IOrganizationRepo> m_organizationRepo;
    std::unique_ptr<IOwnerRepo> m_ownerRepo;
    std::unique_ptr<ITheftCaseRepo> m_theftCaseRepo;
    std::unique_ptr<IVehicleRepo> m_vehicleRepo;
    std::unique_ptr<IVehicleRecordRepo> m_vehicleRecordRepo;

    std::unique_ptr<AccidentManager> m_accidentManager;
    std::unique_ptr<OrganizationManager> m_organizationManager;
    std::unique_ptr<OwnerManager> m_ownerManager;
    std::unique_ptr<TheftCaseManager> m_theftCaseManager;
    std::unique_ptr<VehicleManager> m_vehicleManager;

    std::unique_ptr<CommandInit> m_commandInit;

    void initComponents();

public:
    CLIApp();
public:
    void run();

};
