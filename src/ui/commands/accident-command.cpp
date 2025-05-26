#include <src/ui/commands/accident-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>

void AccidentCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("get statistic by period", 
        []()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod("> ", start, end);

            

        }
    );

    optionMenu.addOption("get analytic", 
        []()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod("> ", start, end);

            
        }
    );

    optionMenu.addOption("get accident statistic by period", 
        []()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod("> ", start, end);

            
        }
    );

    optionMenu.addOption("get drunk statistic", 
        []()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod("> ", start, end);

            
        }
    );

    optionMenu.addOption("get wanted vehicles", 
        []()
        {
            
        }
    );

    optionMenu.start();
}
