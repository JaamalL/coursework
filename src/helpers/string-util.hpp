#pragma once

#include <string>
#include <vector>

namespace StringUtil
{
    std::string join(const std::vector<unsigned int>& arr, const char sep = ' ');

    template <std::size_t size>
    std::string join(const std::string(&arr)[size], const char sep = ' ')
    {
        if (size == 0)
            return "";

        std::string out;
        for (unsigned int i = 1; i < size; ++i)
            out += arr[i] + sep;

        return out;
    }

    const std::vector<unsigned int> splitNumber(const std::string str, const char sep = ' ');
    const std::vector<std::string> splitString(const std::string str, const char sep = ' ');
};
