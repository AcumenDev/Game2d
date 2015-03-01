#include <chrono>
#include "utils/logger/Logger.hpp"
#include <iomanip>
#include <ctime>

std::shared_ptr<Logger> Logger::_logger = nullptr;

std::shared_ptr<Logger> Logger::Get() {
    if (!_logger) {
        _logger.reset(new Logger());
    }
    return _logger;
}

Logger::~Logger() {
}

void Logger::Info(std::string msg) {
    _write("INFO", msg);
}

void Logger::Info(std::string topic, std::string msg) {
    Info(_topicFormat(topic, msg));
}

void Logger::Error(std::string msg) {
    _write("ERROR", msg);
}

void Logger::Error(std::string topic, std::string msg) {
    Error(_topicFormat(topic, msg));
}

void Logger::Warn(std::string msg) {
    _write("WARN", msg);
}

void Logger::Warn(std::string topic, std::string msg) {
    Warn(_topicFormat(topic, msg));
}

void Logger::Debug(std::string msg) {
    _write("DEBUG", msg);
}

void Logger::Debug(std::string topic, std::string msg) {
    Debug(_topicFormat(topic, msg));
}

void Logger::_write(std::string level, std::string msg) {
    std::cout << "[" + _getTime() + "]" << "[" + level + "]:" + msg << std::endl;
}

std::string Logger::_getTime() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = gmtime(&rawtime);

    strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", timeinfo);
    return std::string(buffer);
}

std::string Logger::_topicFormat(std::string topic, std::string msg) {
    return "[" + topic + "] " + msg;
}
