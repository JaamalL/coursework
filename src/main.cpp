#include <iostream>

#include <src/helpers/string-util.hpp>

int main()
{
    std::string str = "1 2 3";
    std::vector<unsigned int> out = StringUtil::splitNumber(str);

    for (unsigned int i = 0; i < out.size(); ++i)
        std::cout << std::to_string(i + 1) << ": " << std::to_string(out[i]) << std::endl;

    return 0;
}
