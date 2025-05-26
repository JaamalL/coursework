#include <iostream>
#include <stdexcept>

#include <src/ui/commands/accident-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/ui/commands/printer.hpp>
#include <src/domain-logic/validator.hpp>

AccidentCommand::AccidentCommand(AccidentManager& accidentManager)
:
    m_accidentManager(accidentManager)
{}

void AccidentCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("add", 
        [&]()
        {
            DateTime dateTime;
            Input::inputDateTime("Time DD-MM-YYYY hh:mm:ss> ", dateTime);

            unsigned int accidentType = 0;
            Input::inputNumber("Accident type:\n0 - PEDESTRAIN_HIT\n1 - OBSTACLE_HIT\n2 - HEAD_ON_HIT\n3 - REAR_END\n4 - SIDE_HIT\n5 - OTHER\n> ", accidentType);
            
            if (!Accident::isValidAccidentType(accidentType))
                throw std::runtime_error("Error: type is not valid");

            std::string location;
            std::cout << "Location> ";
            std::getline(std::cin, location);

            std::string description;
            std::cout << "Description> ";
            std::getline(std::cin, description);

            unsigned int injuredCount = 0;
            Input::inputNumber("Injured count> ", injuredCount);

            float damageCost = 0;
            Input::inputNumber("Damage cost> ", damageCost);

            unsigned int causeType = 0;
            Input::inputNumber("Cause type:\n0 - DRUNK\n1 - BREAK_RULES\n2 - BREAKAGE\n3 - ROAD_CONDITIONS\n4 - OTHER\n> ", causeType);

            std::string roadConditions;
            std::cout << "Road conditions> ";
            std::getline(std::cin, roadConditions);

            unsigned int participantsVehicleCount = 0;
            Input::inputNumber("Participants vehicle count> ", participantsVehicleCount);

            std::string licensePlate;

            std::vector<std::string> participantsVehicles;
            for (unsigned int i = 0; i < participantsVehicleCount; ++i)
            {
                Input::inputLicensePlate("License plate" + std::to_string(i + 1) + " " + 
                    Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);
                participantsVehicles.push_back(licensePlate);
            }

            unsigned int escapedVehicleCount = 0;
            Input::inputNumber("Escaped vehicle count> ", escapedVehicleCount);

            if (escapedVehicleCount > participantsVehicleCount)
                throw std::runtime_error("Error: escaped vehicle count shoud be >= participants vehicle count");

            bool isExistsInParticipants = false;
            std::vector<std::string> escapedVehicles;
            for (unsigned int i = 0; i < escapedVehicleCount; ++i)
            {
                Input::inputLicensePlate("License plate" + std::to_string(i + 1) + " " + 
                    Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

                isExistsInParticipants = false;
                for (unsigned int j = 0; j < participantsVehicles.size(); ++j)
                {
                    if (participantsVehicles[j] == licensePlate)
                    {
                        isExistsInParticipants = true;
                        break;
                    }
                }
                
                if (!isExistsInParticipants)
                    throw std::runtime_error("Error: license palte not exists in participants vehicles");
                
                escapedVehicles.push_back(licensePlate);
            }

            m_accidentManager.createAccident(dateTime, (Accident::AccidentType)accidentType, 
                location, participantsVehicles, description, injuredCount, damageCost, 
                (Accident::CauseType)causeType, roadConditions, escapedVehicles);
        }
    );

    optionMenu.addOption("get statistic by type and period", 
        [&]()
        {
            unsigned int type = 0;
            Input::inputNumber("Accident type:\n0 - PEDESTRAIN_HIT\n1 - OBSTACLE_HIT\n2 - HEAD_ON_HIT\n3 - REAR_END\n4 - SIDE_HIT\n5 - OTHER\n> ", type);

            if (!Accident::isValidAccidentType(type))
                throw std::runtime_error("Error: type is not valid");

            DateTime start;
            DateTime end;
            Input::inputPeriod(" DD-MM-YYYY hh:mm:ss> ", start, end);

            std::unique_ptr<AccidentStatisticDTO> stat = m_accidentManager.getStatisticByTypeAndPeriod(
                (Accident::AccidentType)type, start, end);

            std::cout << "==========================================\n";
            std::cout << "Total accidents: " << stat->total << std::endl;
            std::cout << "Total parti participant vehicles: " << stat->totalParticipantVehicles << std::endl;
            std::cout << "Total escaped vehicles: " << stat->totalEscapedVehicles << std::endl;
            std::cout << "Total injured count: " << stat->totalInjuredCount << std::endl;
            std::cout << "Total damage cost: " << stat->totalDamageCost << std::endl;
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get analysis", 
        [&]()
        {
            std::unique_ptr<AccidentAnalysisDTO> ana = m_accidentManager.getAnalysis();

            std::cout << "==========================================\n";
            std::cout << "Most popular couse: " << ana->mostPopularCouse << std::endl;
            for (unsigned int i = 0; i < ana->mostDanagerousLocations.size(); ++i)
                std::cout << "Top" << (i + 1) << " danagerous location: " 
                    << ana->mostDanagerousLocations[i] << std::endl;
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get drunk statistic", 
        [&]()
        {
            std::unique_ptr<AccidentDrunkDTO> stat = m_accidentManager.getDrunkStatistic();

            std::cout << "==========================================\n";
            std::cout << "Total drunk accidents: " << stat->total << std::endl;
            std::cout << "Drunk accidents part: " << stat->part * 100 << "%" << std::endl;
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get wanted vehicles", 
        [&]()
        {
            std::vector<VehicleDTO> escapedVehicles = m_accidentManager.getEscapedVehicles();

            Printer::printVehicles(escapedVehicles);
        }
    );

    optionMenu.start();
}
