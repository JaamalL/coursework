#include <iostream>

#include <src/ui/commands/printer.hpp>

void Printer::printVehicle(const VehicleDTO& vehicle)
{
    std::cout << "==========================================\n";
    std::cout << "License palte: " << vehicle.licensePlate << std::endl;
    std::cout << "Type: " << vehicle.type << std::endl;
    std::cout << "Brand: " << vehicle.brand << std::endl;
    std::cout << "Release year: " << vehicle.releaseYear << std::endl;
    std::cout << "Engine volume: " << vehicle.engineVolume << std::endl;
    std::cout << "Engine serial number: " << vehicle.engineSerialNumber << std::endl;
    std::cout << "Chassis serial number: " << vehicle.chassisSerialNumber << std::endl;
    std::cout << "Body serial number: " << vehicle.bodySerialNumber << std::endl;
    std::cout << "Color: " << vehicle.color << std::endl;
    std::cout << "Is passed inspection: " << vehicle.isPassedInspection << std::endl;
    std::cout << "Is accident: " << vehicle.isAccident << std::endl;
}
void Printer::printVehicles(const std::vector<VehicleDTO>& vehicles)
{
    std::cout << "==========================================\n";
    std::cout << "Total vehicles: " << vehicles.size();

    for (unsigned int i = 0 ; i < vehicles.size(); ++i)
        printVehicle(vehicles[i]);
    std::cout << "==========================================\n";
}
