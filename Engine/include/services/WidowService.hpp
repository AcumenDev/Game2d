#ifndef WIDOWSERVICE_H
#define WIDOWSERVICE_H
#include <iostream>
#include <memory>
#include "utils/logger/Logger.hpp"
#include "Window.hpp"
class WidowService {
public:
    WidowService(std::shared_ptr<Logger> log);
    std::shared_ptr<Window> Create(std::string title, int x, int y, int w, int h);
    virtual ~WidowService();
protected:
private:
    std::shared_ptr<Logger> _log;
};

#endif // WIDOWSERVICE_H
