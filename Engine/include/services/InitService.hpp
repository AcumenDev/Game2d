#ifndef INITSERVICE_H
#define INITSERVICE_H
#include <iostream>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Logger.hpp"
class InitService {
public:
    InitService(std::shared_ptr<Logger> log);
    bool Init();
    virtual ~InitService() ;
protected:
private:
    std::shared_ptr<Logger> _log;
};
#endif // INITSERVICE_H


