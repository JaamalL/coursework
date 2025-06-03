#include <iostream>

#include <src/ui/commands/theft-case-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/ui/commands/printer.hpp>
#include <src/domain-logic/validator.hpp>

TheftCaseCommand::TheftCaseCommand(TheftCaseManager& theftCaseManager)
:
    m_theftCaseManager(theftCaseManager)
{}

void TheftCaseCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("create", 
        [&]()
        {
            DateTime dateTime;
            Input::inputDateTime("Time DD-MM-YYYY hh:mm:ss> ", dateTime);

            std::string location;
            std::cout << "Location> ";
            std::getline(std::cin, location);

            std::string hackingMethod;
            std::cout << "Hacking method> ";
            std::getline(std::cin, hackingMethod);

            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

            m_theftCaseManager.createTheftCase(dateTime, location, hackingMethod, licensePlate);
        }
    );

    optionMenu.addOption("get search efficiency", 
        [&]()
        {
            float searchEfficiency = m_theftCaseManager.getSearchEfficiency();

            std::cout << "==========================================\n";
            std::cout << "Search efficiency: " << searchEfficiency * 100 << "%" << std::endl;
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get by period", 
        [&]()
        {
            DateTime start;
            DateTime end;
            Input::inputPeriod(" DD-MM-YYYY hh:mm:ss> ", start, end);

            std::vector<TheftCaseDTO> theftCases = m_theftCaseManager.getByPeriod(start, end);

            std::cout << "==========================================\n";
            std::cout << "Total theft cases: " << theftCases.size() << std::endl;

            for (unsigned int i = 0; i < theftCases.size(); ++i)
            {
                std::cout << "==========================================\n";
                std::cout << "Time: " << theftCases[i].dateTime.toSring() << std::endl;
                std::cout << "Location: " << theftCases[i].location << std::endl;
                std::cout << "Hacking method: " << theftCases[i].hackingMethod << std::endl;
                std::cout << "Vehicle license plate: " << theftCases[i].licensePlate << std::endl;
                std::cout << "Is found: " << theftCases[i].isFound << std::endl;
            }
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get statistic", 
        [&]()
        {
            std::unique_ptr<TheftCaseStatisticDTO> stat = m_theftCaseManager.getStatistic();
            
            std::cout << "==========================================\n";
            std::cout << "Total brands: " << stat->mostPopularBrands.size() << std::endl;
            std::cout << "Total vehicle types: " << stat->mostPopularVehicleTypes.size() << std::endl;
            std::cout << "==========================================\n";

            for (unsigned int i = 0; i < stat->mostPopularBrands.size(); ++i)
                std::cout << "Top" << (i + 1) << " brand: " << stat->mostPopularBrands[i] << std::endl;

            if (stat->mostPopularBrands.size() > 0)
                std::cout << "==========================================\n";

            for (unsigned int i = 0; i < stat->mostPopularVehicleTypes.size(); ++i)
                std::cout << "Top" << (i + 1) << " vehicle type: " << stat->mostPopularVehicleTypes[i] << std::endl;
    
            if (stat->mostPopularVehicleTypes.size() > 0)
                std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get wanted vehicles", 
        [&]()
        {
            std::vector<VehicleDTO> theftCaseVehicles = m_theftCaseManager.getTheftVehicles();

            Printer::printVehicles(theftCaseVehicles);
        }
    );

    optionMenu.addOption("set found", 
        [&]()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

            m_theftCaseManager.setFound(licensePlate);
        }
    );

    optionMenu.start();
}
