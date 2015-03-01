#ifndef SPRITEANIMATIONMANAGER_H
#define SPRITEANIMATIONMANAGER_H

#include <memory>
#include <fstream>
#include "SpriteAnimation.hpp"
#include "settings/SystemSettings.hpp"
#include "utils/logger/Logger.hpp"
#include "BaseResourceManager.hpp"
#include "settings/SystemSettings.hpp"
#include "Utils/fileSystem/FileSystemUtils.hpp"

#include "rapidjson/document.h"

using std::shared_ptr;
using std::string;
using namespace rapidjson;

class SpriteAnimationResourceManager : public  BaseResourceManager<shared_ptr<SpriteAnimation>> {
public:
    SpriteAnimationResourceManager(shared_ptr<SystemSettings> systemSettings, SDL_Renderer *render);

    shared_ptr<SpriteAnimation> getResourse(string  name) override;

private:
    string _name;
    shared_ptr<SystemSettings> _systemSettings;
    SDL_Renderer *_render;
};

#endif // SPRITEANIMATIONMANAGER_H


