#ifndef WIDOWSERVICE_H
#define WIDOWSERVICE_H
#include <iostream>
#include <memory>
#include "utils/logger/Logger.hpp"
#include "Window.hpp"
#include "render/Render.hpp"

using std::make_shared;
using std::shared_ptr;
using std::string;
class WidowService {
public:
    WidowService(shared_ptr<Logger> log);
    shared_ptr<Window> Create(string title, int x, int y, int w, int h);
    virtual ~WidowService();
protected:
private:
    shared_ptr<Logger> _log;
};

#endif // WIDOWSERVICE_H
