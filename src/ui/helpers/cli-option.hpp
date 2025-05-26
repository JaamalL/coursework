#pragma once

#include <string>
#include <functional>
#include <vector>

class CLIOption
{
private:
    struct Opt
    {
        std::string description;
        std::function<void()> handler;
    };
private:
    std::vector<Opt> m_options;

public:
    CLIOption() = default;
public:
    void addOption(const std::string optDescription, const std::function<void()> optHandler);
    void start();

};
