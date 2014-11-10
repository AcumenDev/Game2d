#include "Logger.hpp"

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}
void Logger::Info(std::string msg)
{
    std::cout<<msg<<std::endl;
}
