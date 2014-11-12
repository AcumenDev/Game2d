#include "Logger.hpp"
void Logger::Info(std::string msg) {
    _write("INFO : "+msg);
}
void Logger::Error(std::string msg) {
    _write("ERROR : "+msg);
}

void Logger::Warn(std::string msg) {
    _write("WARN : "+msg);
}

void Logger::Debug(std::string msg) {
    _write("DEBUG : "+msg);
}

void Logger::_write(std::string msg) {
    std::cout<<msg<<std::endl;
}
