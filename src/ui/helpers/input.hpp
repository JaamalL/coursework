#pragma once

#include <string>

#include <src/helpers/date-time.hpp>

namespace Input 
{
    void inputNumber(const std::string question, unsigned int& out);
    void inputNumber(const std::string question, float& out);
    void inputLogic(const std::string question, bool& out);
    void inputDateTime(const std::string question, DateTime& out);
    void inputPeriod(const std::string question, DateTime& start, DateTime& end);
    void inputLicensePlate(const std::string question, std::string& out);
    void inputPhoneNumber(const std::string question, std::string& out);
    void inputSerialNumber(const std::string question, std::string& out);
};
