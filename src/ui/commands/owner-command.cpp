#include <src/ui/helpers/input.hpp>
#include <src/ui/commands/owner-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/domain-logic/validator.hpp>

void OwnerCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("get details by license plate", 
        []()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

            
        }
    );

    optionMenu.addOption("get who did not pass inspection on time", 
        []()
        {

            
        }
    );

    optionMenu.start();
}
