#ifndef TEXTURESRESOURCEMANAGER_H
#define TEXTURESRESOURCEMANAGER_H
#include <memory>
#include <vector>
#include "Utils/Rectangle.hpp"
#include "Texture.hpp"
#include "utils/logger/Logger.hpp"
#include "BaseResourceManager.hpp"


using std::vector;
using std::shared_ptr;
using std::string;

class TexturesResourceManager : public  BaseResourceManager<shared_ptr<Texture>>
{
public:
    TexturesResourceManager(SDL_Renderer *render);
    virtual ~TexturesResourceManager();
    shared_ptr<Texture> getResourse(string path);
protected:
private:
    SDL_Renderer *_render;
    std::string _name;
};

#endif // TEXTURESRESOURCEMANAGER_H
