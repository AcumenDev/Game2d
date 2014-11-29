#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
class Logger {
public:
    Logger() {}
    virtual ~Logger() {}
    void Info(std::string msg);
    void Info(std::string topic, std::string msg);
    void Error(std::string msg);
    void Error(std::string topic, std::string msg);
    void Warn(std::string msg);
    void Warn(std::string topic, std::string msg);
    void Debug(std::string msg);
    void Debug(std::string topic, std::string msg);
protected:
private:
    void _write(std::string level, std::string msg);
    std::string _topicFormat(std::string topic, std::string msg);
    std::string _getTime();
};
#endif // LOGGER_H
