#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Texture.hpp"

class ResourceManager {
public:
    ResourceManager();
    virtual ~ResourceManager();
    Texture * GetTextureFromFile(SDL_Renderer* render, std::string path);
protected:
private:
};

#endif // RESOURCEMANAGER_H
