#pragma once

#include <ctime>
#include <string>

// DD-MM-YYYY hh:mm:ss
class DateTime
{
private:
    time_t m_dateTime;
    std::string m_dateTimeStr;

    static std::string m_dateTimeFormat;

public:
    DateTime();
    DateTime(const std::string dateTime);
public:
    bool operator<(const DateTime& obj) const;
    bool operator>(const DateTime& obj) const;
    bool operator>=(const DateTime& obj) const;
    bool operator<=(const DateTime& obj) const;
public:
    std::string toSring() const;

    static std::string nowToString();

};
