#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>


class Logger
{
    public:
        Logger();
        virtual ~Logger();
        void Info(std::string msg);
    protected:
    private:
};

#endif // LOGGER_H
