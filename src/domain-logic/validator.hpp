#pragma once

#include <string>

namespace Validator
{
    const std::string LICENSE_PLATE_TEMPLATE = "XXXX-SS";
    const std::string LICENSE_PLATE_SERIES_TEMPLATE = "SS";
    bool isValidLicensePlate(const std::string& licensePlate);
    bool isValidLicensePlateSeries(const std::string& series);

    std::string getLicensePlateSeries(const std::string& licensePlate);

    const std::string SERIAL_NUMBER_TEMPLATE = "XXX-XXX-XXX";
    bool isValidSerialNumber(const std::string& serialNumber);

    const std::string PHONE_NUMBER_TEMPLATE = "XXX-XXX-XX-XX";
    bool isValidPhoneNumber(const std::string phoneNumber);

};
