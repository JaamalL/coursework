#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdexcept>

#include <src/helpers/date-time.hpp>

DateTime::DateTime()
:
    m_dateTime(0),
    m_dateTimeStr("00-00-0000 00:00:00")
{}
DateTime::DateTime(const std::string dateTime)
:
    m_dateTimeStr(dateTime)
{
    std::tm t;
    std::istringstream ss(dateTime);

    std::get_time(&t, "%d-%m-%Y %H:%M:%S");

    if (ss.fail())
        throw std::runtime_error("Error: failed to parse time");

    m_dateTime = std::mktime(&t);

    if (m_dateTime == -1)
        throw std::runtime_error("Error: failed to parse time");
}

bool DateTime::operator<(const DateTime& obj) const
{
    return m_dateTime < obj.m_dateTime;
}
bool DateTime::operator>(const DateTime& obj) const
{
    return m_dateTime > obj.m_dateTime;
}
bool DateTime::operator>=(const DateTime& obj) const
{
    return m_dateTime >= obj.m_dateTime;
}
bool DateTime::operator<=(const DateTime& obj) const
{
    return m_dateTime <= obj.m_dateTime;
}

std::string DateTime::toSring() const { return m_dateTimeStr; }
