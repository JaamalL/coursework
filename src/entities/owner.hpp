#pragma once

#include <string>
#include <vector>

#include <src/entities/entity.hpp>

class Owner : public Entity<Owner>
{
private:
    std::string m_phoneNumber;
    std::string m_surname;
    std::string m_name;
    std::string m_patronymic;
    std::string m_address;
    std::vector<unsigned int> m_vehicleIds;

public:
    Owner(const std::string phoneNumber, const std::string surname, const std::string name, 
        const std::string patronymic, const std::string address, std::vector<unsigned int>& vehicleIds);
    ~Owner() = default;
public:
    std::string                getPhoneNumber() const;
    std::string                getSurname() const;
    std::string                getName() const;
    std::string                getPatronymic() const;
    std::string                getAddress() const;
    std::vector<unsigned int>& getVehicleIds() const;
    
    void setPhoneNumber(const std::string phoneNumber);
    void setSurname(const std::string surname);
    void setName(const std::string name);
    void setPatronymic(const std::string patronymic);
    void setAddress(const std::string address);

};
