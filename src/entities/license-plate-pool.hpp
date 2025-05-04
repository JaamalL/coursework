#pragma once

#include <string>
#include <list>

class LicensePlatePool
{
public:
    struct Range
    {
        unsigned int start;
        unsigned int end;
    };

private:
    std::string m_series;
    Range m_baseRange;
    std::list<Range> m_freeRanges;

public:
    LicensePlatePool(const std::string series, const Range baseRange);
    ~LicensePlatePool() = default;
public:
    std::string         getSeries() const;
    Range               getBaseRange() const;
    std::list<Range>&   getRanges() const;

    void setSeries(const std::string series);

};
