#ifndef TEXTURESRESOURCEMANAGER_H
#define TEXTURESRESOURCEMANAGER_H
#include <memory>
#include <vector>
#include "settings/SystemSettings.hpp"
#include "Utils/Rectangle.hpp"
#include "Texture.hpp"
#include "utils/logger/Logger.hpp"
#include "BaseResourceManager.hpp"
#include "Utils/fileSystem/FileSystemUtils.hpp"


using std::vector;
using std::shared_ptr;
using std::string;

class TexturesResourceManager : public  BaseResourceManager<shared_ptr<Texture>>
{
public:
    TexturesResourceManager(shared_ptr<SystemSettings> systemSettings,SDL_Renderer *render);
    virtual ~TexturesResourceManager();
    shared_ptr<Texture> getResourse(string name);
protected:
private:
    SDL_Renderer *_render;
    shared_ptr<SystemSettings> _systemSettings;
    std::string _name;
};

#endif // TEXTURESRESOURCEMANAGER_H
