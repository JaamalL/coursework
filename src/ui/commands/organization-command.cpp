#include <iostream>
#include <string>

#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/commands/organization-command.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/helpers/date-time.hpp>
#include <src/domain-logic/validator.hpp>

OrganizationCommand::OrganizationCommand(OrganizationManager& organizationManager)
:
    m_organizationManager(organizationManager)
{}

void OrganizationCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("create", 
        [&]()
        {
            std::string organizationName;
            std::cout << "Organization name> ";
            std::getline(std::cin, organizationName);

            std::string address;
            std::cout << "Address> ";
            std::getline(std::cin, address);

            std::string managerFullName;
            std::cout << "Manager full name> ";
            std::getline(std::cin, managerFullName);

            unsigned int vehicleRecordCount = 0;
            Input::inputNumber("Vehicle record count> ", vehicleRecordCount);

            std::vector<VehicleRecordDTO> vehicleRecords;
            VehicleRecordDTO record;
            for (unsigned int i = 0; i < vehicleRecordCount; ++i)
            {
                Input::inputDateTime("Time" + std::to_string(i + 1) + 
                    " DD-MM-YYYY hh:mm:ss> ", record.dateTime);
                Input::inputLicensePlate("License plate" + std::to_string(i + 1) + " " + 
                    Validator::LICENSE_PLATE_TEMPLATE + "> ", record.licensePlate);
                vehicleRecords.push_back(record);
            }

            m_organizationManager.createOrganization(organizationName, address, managerFullName, vehicleRecords);;
        }
    );

    optionMenu.addOption("get by license plate series", 
        [&]()
        {
            std::string inp;

            for (;;)
            {
                std::cout << "License number series " << 
                    Validator::LICENSE_PLATE_SERIES_TEMPLATE << "> ";
                std::getline(std::cin, inp);

                if (inp == "exit")
                    throw std::runtime_error("Exit");

                if (Validator::isValidLicensePlateSeries(
                    inp))
                    break;
                
                std::cout << "Error: invalid license plate series\n";
            }

            std::vector<OrganizationDTO> organizations = m_organizationManager.getBySeries(inp);

            printOrganizations(organizations);
        }
    );

    optionMenu.addOption("get by license plate received during the period", 
        [&]()
        {
            DateTime start;
            DateTime end;

            Input::inputPeriod(" DD-MM-YYYY hh:mm:ss> ", start, end);

            std::vector<OrganizationDTO> organizations = m_organizationManager.getByRecievedPeriod(start, end);
            
            printOrganizations(organizations);
        }
    );

    optionMenu.start();
}

void OrganizationCommand::printOrganizations(const std::vector<OrganizationDTO>& organizations)
{
    std::cout << "==========================================\n";
    std::cout << "Total organizations: " << organizations.size() << std::endl;
        
    for (unsigned int i = 0 ; i < organizations.size(); ++i)
    {
        std::cout << "==========================================\n";
        std::cout << "Organization name: " << organizations[i].organizationName << std::endl;
        std::cout << "Address: " << organizations[i].address << std::endl;
        std::cout << "Manager full name: " << organizations[i].managerFullName << std::endl;
    }
    std::cout << "==========================================\n";
}
