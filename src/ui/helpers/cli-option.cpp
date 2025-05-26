#include <exception>
#include <iostream>

#include <src/ui/helpers/cli-option.hpp>
#include <src/ui/helpers/input.hpp>

void CLIOption::addOption(const std::string optDescription, 
    const std::function<void()> optHandler)
{
    m_options.push_back({ optDescription, optHandler });
}
void CLIOption::start()
{
    for (unsigned int i = 0; i < m_options.size(); ++i)
        std::cout << std::to_string(i) << " - " + m_options[i].description << std::endl;


    unsigned int opt = 0;
    
    for (;;)
    {
        try
        {
            Input::inputNumber("> ", opt);
        } 
        catch (std::exception& ex) 
        {
            std::cout << ex.what() << std::endl;
            return;
        }

        if (opt < m_options.size())
            break;
        
        std::cout << "Error: invalid option\n";
    }

    try 
    {
        m_options[opt].handler();
    } 
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
