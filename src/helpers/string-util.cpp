#include <sstream>

#include <src/helpers/string-util.hpp>

std::string StringUtil::join(const std::vector<unsigned int>& arr, const char sep)
{
    if (arr.size() == 0)
        return "";

    std::string out;
    
    for (unsigned int i = 1; i < arr.size(); ++i)
        out += std::to_string(arr[i]) + sep;

    return out;
}

const std::vector<unsigned int> StringUtil::splitNumber(const std::string str, const char sep)
{
    std::vector<unsigned int> out;
    std::stringstream ss(str);
    std::string part;

    while (std::getline(ss, part, sep))
        if (!part.empty())
            out.push_back(std::stoul(part));

    return out;
}
const std::vector<std::string> StringUtil::splitString(const std::string str, const char sep)
{
    std::vector<std::string> out;
    std::stringstream ss(str);
    std::string part;

    while (std::getline(ss, part, sep))
        out.push_back(part);

    return out;
}
