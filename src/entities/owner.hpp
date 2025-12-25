#pragma once

#include <string>

#include <src/entities/entity.hpp>

struct OwnerDTO
{
    std::string phoneNumber;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;
};

class Owner : public Entity<Owner>
{
private:
    std::string m_phoneNumber;
    std::string m_surname;
    std::string m_name;
    std::string m_patronymic;
    std::string m_address;

public:
    Owner(const std::string phoneNumber, const std::string surname, const std::string name, 
        const std::string patronymic, const std::string address);
    Owner(const unsigned int id, const std::string phoneNumber, const std::string surname, 
        const std::string name, const std::string patronymic, const std::string address);
public:
    std::string getPhoneNumber() const;
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;
    std::string getAddress() const;

};
