#include <iostream>

#include <src/ui/cli-app.hpp>
#include <src/data/file-accident-repo.hpp>
#include <src/data/file-organization-repo.hpp>
#include <src/data/file-owner-repo.hpp>
#include <src/data/file-theft-case-repo.hpp>
#include <src/data/file-vehicle-repo.hpp>
#include <src/data/file-vehicle-record-repo.hpp>

CLIApp::CLIApp()
{
    initComponents();
}

void CLIApp::run()
{
    std::string input;

    for (;;)
    {
        std::cout << "[\033[32m" + DateTime::nowToString() +"\033[0m]# ";
        std::getline(std::cin, input);

        if (input == "")
            continue;

        ICommand* command = m_commandInit->getCommand(input);
        if (command == nullptr)
        {
            std::cout << "Error: command not found\n";
            std::cout << "Try 'help' for available commands\n";
            continue;
        }

        try 
        {
            command->execute();
        } 
        catch (std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
            return;
        }
    }
}

void CLIApp::initComponents()
{
    m_accidentRepo = std::make_unique<FileAccidentRepo>();
    m_organizationRepo = std::make_unique<FileOrganizationRepo>();
    m_ownerRepo = std::make_unique<FileOwnerRepo>();
    m_theftCaseRepo = std::make_unique<FileTheftCaseRepo>();
    m_vehicleRepo = std::make_unique<FileVehicleRepo>();
    m_vehicleRecordRepo = std::make_unique<FileVehicleRecordRepo>();

    m_accidentManager = std::make_unique<AccidentManager>(*m_accidentRepo, *m_vehicleRepo);
    m_organizationManager = std::make_unique<OrganizationManager>(*m_organizationRepo, 
        *m_vehicleRepo, *m_vehicleRecordRepo);
    m_ownerManager = std::make_unique<OwnerManager>(*m_ownerRepo, *m_vehicleRepo);
    m_theftCaseManager = std::make_unique<TheftCaseManager>(*m_theftCaseRepo, *m_vehicleRepo);
    m_vehicleManager = std::make_unique<VehicleManager>(*m_vehicleRepo, *m_ownerRepo);

    m_commandInit = std::make_unique<CommandInit>(*m_accidentManager, 
        *m_organizationManager, *m_ownerManager, 
        *m_theftCaseManager, *m_vehicleManager);
}
