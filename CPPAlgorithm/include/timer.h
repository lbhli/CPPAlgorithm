#pragma once
#include <ctime>
#include <string>
#include <iostream>

class timer
{
public:
    timer() :m_strName("")
    {
        m_starttime = std::clock();
        std::cout << m_strName << " is startting. " << std::endl;
    };

    timer(std::string str) :m_strName(str)
    {
        m_starttime = std::clock();
        std::cout << m_strName << " is startting. " << std::endl;
    };

    ~timer()
    {
        std::cout << m_strName << " cost time:" << (double)(std::clock() - m_starttime) / CLOCKS_PER_SEC << std::endl;
    };
private:
    std::clock_t m_starttime;
    std::string m_strName;
}; 