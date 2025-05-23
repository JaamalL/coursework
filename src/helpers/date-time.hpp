#pragma once

#include <ctime>
#include <string>

class DateTime
{
private:
    time_t m_dateTime;
    std::string m_dateTimeStr;

public:
    DateTime();
    DateTime(const std::string dateTime);
    ~DateTime() = default;
public:
    bool operator<(const DateTime& obj);
    bool operator>(const DateTime& obj);
    bool operator>=(const DateTime& obj);
    bool operator<=(const DateTime& obj);

};
