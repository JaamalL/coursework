#include <src/ui/commands/vehicle-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/domain-logic/validator.hpp>

void VehicleCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("get card by license plate", 
        []()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);
            
            
        }
    );

    optionMenu.start();
}
