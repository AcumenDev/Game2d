#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>

class Logger {
public:
    static std::shared_ptr<Logger> Get();

    virtual ~Logger();

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
    Logger() {}
    Logger( const Logger& ){};

    Logger& operator=( Logger& ){        };
    static std::shared_ptr<Logger> _logger;

    void _write(std::string level, std::string msg);

    std::string _topicFormat(std::string topic, std::string msg);

    std::string _getTime();
};

#endif // LOGGER_H
