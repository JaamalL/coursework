#include <regex>
#include <stdexcept>

#include <src/domain-logic/validator.hpp>

bool Validator::isValidLicensePlate(const std::string& licensePlate)
{
    std::regex pattern("^\\d{4}-[A-Z]{2}$");

    return std::regex_match(licensePlate, pattern);
}
bool Validator::isValidLicensePlateSeries(const std::string& series)
{
    std::regex pattern("^[A-Z]{2}$");

    return std::regex_match(series, pattern);
}

std::string Validator::getLicensePlateSeries(const std::string& licensePlate)
{
    if (licensePlate.size() != 7)
        throw std::runtime_error("Error: license plate size is not valid");

    return licensePlate.substr(5);
}

bool Validator::isValidSerialNumber(const std::string& serialNumber)
{
    std::regex pattern("^\\d{3}-\\d{3}-\\d{3}$");

    return std::regex_match(serialNumber, pattern);
}

bool Validator::isValidPhoneNumber(const std::string phoneNumber)
{
    std::regex pattern("^\\d{3}-\\d{3}-\\d{2}-\\d{2}$");

    return std::regex_match(phoneNumber, pattern);
}
