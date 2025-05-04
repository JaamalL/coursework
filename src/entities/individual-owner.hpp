#pragma once

#include <src/entities/owner.hpp>

class IndividualOwner : public Owner
{
private:
    std::string m_phoneNumber;
    std::string m_surname;
    std::string m_name;
    std::string m_patronymic;
    std::string m_address;
    std::vector<Vehicle*> m_vehicles;

public:
    IndividualOwner();
    ~IndividualOwner() = default;
public:
    std::string            getPhoneNumber() const;
    std::string            getSurname() const;
    std::string            getName() const;
    std::string            getPatronymic() const;
    std::string            getAddress() const;
    std::vector<Vehicle*>& getVehicles() const;
    
    void setPhoneNumber(const std::string phoneNumber);
    void setSurname(const std::string surname);
    void setName(const std::string name);
    void setPatronymic(const std::string patronymic);
    void setAddress(const std::string address);

};
