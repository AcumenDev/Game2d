#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
class Logger {
public:
    Logger() {}
    virtual ~Logger() {}
    void Info(std::string msg);
    void Error(std::string msg);
    void Warn(std::string msg);
    void Debug(std::string msg);
protected:
private:
    void _write(std::string msg);
};
#endif // LOGGER_H
