#include <src/entities/owner.hpp>

Owner::Owner(const std::string phoneNumber, const std::string surname, const std::string name, 
    const std::string patronymic, const std::string address)
:
    m_phoneNumber(phoneNumber),
    m_surname(surname),
    m_name(name),
    m_patronymic(patronymic),
    m_address(address)
{}
Owner::Owner(const unsigned int id, const std::string phoneNumber, const std::string surname, 
    const std::string name, const std::string patronymic, const std::string address)
:
    Entity(id),
    m_phoneNumber(phoneNumber),
    m_surname(surname),
    m_name(name),
    m_patronymic(patronymic),
    m_address(address)
{}

std::string Owner::getPhoneNumber() const { return m_phoneNumber; }
std::string Owner::getSurname() const { return m_surname; }
std::string Owner::getName() const { return m_name; }
std::string Owner::getPatronymic() const { return m_patronymic; }
std::string Owner::getAddress() const { return m_address; }
