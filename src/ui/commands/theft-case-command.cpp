#include <src/ui/commands/theft-case-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>

void TheftCaseCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("get search efficiency", 
        []()
        {

        }
    );

    optionMenu.addOption("get by period", 
        []()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod("> ", start, end);


        }
    );

    optionMenu.addOption("get statistic", 
        []()
        {
            
        }
    );

    optionMenu.addOption("get wanted vehicles", 
        []()
        {
            
        }
    );

    optionMenu.addOption("set found", 
        []()
        {
            
        }
    );

    optionMenu.start();
}
