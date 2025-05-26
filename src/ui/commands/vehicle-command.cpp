#include <iostream>
#include <stdexcept>

#include <src/ui/commands/vehicle-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>
#include <src/domain-logic/validator.hpp>
#include <src/ui/commands/printer.hpp>

VehicleCommand::VehicleCommand(VehicleManager& vehicleManager)
:
    m_vehicleManager(vehicleManager)
{}

void VehicleCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("create", 
        [&]()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

            unsigned int type = 0;
            Input::inputNumber("Vehicle type:\n0 - CAR_PASSENGER\n1 - CAR_TRUCK\n2 - TRAILER\n3 - SEMI_TRAILER\n4 - MOTO\n5 - TRACTOR\n6 - BUS\n7 - BUS_MINI\n> ", type);

            if (!Vehicle::isValidVehicleType(type))
                throw std::runtime_error("Error: invalid option");

            std::string brand;
            std::cout << "Brand> ";
            std::getline(std::cin, brand);

            unsigned int releaseYear = 0;
            Input::inputNumber("Release year> ", releaseYear);

            float engineVolume = 0;
            Input::inputNumber("Engine volume> ", engineVolume);

            std::string engineSerialNumber;
            Input::inputSerialNumber("Engine serial number " + 
                Validator::SERIAL_NUMBER_TEMPLATE + "> ", engineSerialNumber);
            
            std::string chassisSerialNumber;
            Input::inputSerialNumber("Chassis serial number " + 
                Validator::SERIAL_NUMBER_TEMPLATE + "> ", chassisSerialNumber);

            std::string bodySerialNumber;
            Input::inputSerialNumber("Body serial number " + 
                Validator::SERIAL_NUMBER_TEMPLATE + "> ", bodySerialNumber);

            std::string color;
            std::cout << "Color> ";
            std::getline(std::cin, color);

            bool isPassedInspection = false;
            Input::inputLogic("Passed inspection yes/no>", isPassedInspection);

            bool isAccident = false;
            Input::inputLogic("Accident yes/no>", isAccident);

            std::string ownerPhoneNumber;
            Input::inputPhoneNumber("Owner phone number " + Validator::PHONE_NUMBER_TEMPLATE + 
                "> ", ownerPhoneNumber);

            m_vehicleManager.createVehicle(licensePlate, (Vehicle::VehicleType)type, brand, 
                releaseYear, engineVolume, engineSerialNumber, chassisSerialNumber, 
                bodySerialNumber, color, isPassedInspection, isAccident, ownerPhoneNumber);
        }
    );

    optionMenu.addOption("get card by license plate", 
        [&]()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);
            
            std::unique_ptr<VehicleDTO> vehicle = m_vehicleManager.getVehicleByLicensePlate(licensePlate);

            Printer::printVehicle(*vehicle);
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get all licnese plates", 
        [&]()
        {
            std::vector<std::string> licensePlates = m_vehicleManager.getVehicleLicensePlates();

            std::cout << "==========================================\n";
            std::cout << "License plate count: " << licensePlates.size() << std::endl;
            std::cout << "==========================================\n";
            
            for (unsigned int i = 0; i < licensePlates.size(); ++i)
                std::cout << (i + 1) << ": " << licensePlates[i] << std::endl;
            std::cout << "==========================================\n";
        }
    );

    optionMenu.start();
}
