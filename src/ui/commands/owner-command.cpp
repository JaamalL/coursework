#include <iostream>

#include <src/ui/helpers/input.hpp>
#include <src/ui/commands/owner-command.hpp>
#include <src/ui/helpers/cli-option.hpp>
#include <src/domain-logic/validator.hpp>

OwnerCommand::OwnerCommand(OwnerManager& ownerManager)
:
    m_ownerManager(ownerManager)
{}

void OwnerCommand::execute()
{
    CLIOption optionMenu;

    optionMenu.addOption("create", 
        [&]()
        {
            std::string phoneNumber;
            Input::inputPhoneNumber("Phone number " + Validator::PHONE_NUMBER_TEMPLATE + "> ", 
                phoneNumber);

            std::string surname;
            std::cout << "Surname> ";
            std::getline(std::cin, surname);

            std::string name;
            std::cout << "Name> ";
            std::getline(std::cin, name);

            std::string patronymic;
            std::cout << "Patronymic> ";
            std::getline(std::cin, patronymic);

            std::string address;
            std::cout << "Address> ";
            std::getline(std::cin, address);

            m_ownerManager.createOwner(phoneNumber, surname, name, patronymic, address);
        }
    );

    optionMenu.addOption("get details by license plate", 
        [&]()
        {
            std::string licensePlate;
            Input::inputLicensePlate("License plate " + 
                Validator::LICENSE_PLATE_TEMPLATE + "> ", licensePlate);

            std::unique_ptr<OwnerDTO> owner = m_ownerManager.getOwnerByLicensePlate(licensePlate);

            printOwner(*owner);
            std::cout << "==========================================\n";
        }
    );

    optionMenu.addOption("get who did not pass inspection on time", 
        [&]()
        {
            std::vector<OwnerDTO> owners = m_ownerManager.getOwnersByNotPassedInspection();

            std::cout << "==========================================\n";
            std::cout << "Total owners: " << owners.size() << std::endl;

            for (unsigned int i = 0; i < owners.size(); ++i)
                printOwner(owners[i]);
            std::cout << "==========================================\n";
        }
    );

    optionMenu.start();
}

void OwnerCommand::printOwner(const OwnerDTO& owner)
{
    std::cout << "==========================================\n";
    std::cout << "Surname: " << owner.surname << std::endl;
    std::cout << "Name: " << owner.name << std::endl;
    std::cout << "Patronymic: " << owner.patronymic << std::endl;
    std::cout << "Phone number: " << owner.phoneNumber << std::endl;
    std::cout << "Address: " << owner.address << std::endl;
}
