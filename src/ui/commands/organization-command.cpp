#include <iostream>
#include <stdexcept>
#include <string>

#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/commands/organization-command.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/helpers/date-time.hpp>
#include <src/domain-logic/validator.hpp>

void OrganizationCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("get by license plate series", 
        []()
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


        }
    );

    optionMenu.addOption("get by license plate received during the period", 
        []()
        {
            DateTime start;
            DateTime end;

            Input::inputPeriod("> ", start, end);


        }
    );

    optionMenu.start();
}
