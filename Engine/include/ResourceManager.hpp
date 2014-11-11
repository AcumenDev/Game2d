#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "Texture.hpp"
#include "Logger.hpp"
#include <memory>
class ResourceManager {
public:
    ResourceManager();
    virtual ~ResourceManager();
    std::shared_ptr<Texture> GetTextureFromFile(SDL_Renderer* render, std::string path);
protected:
private:
};

#endif // RESOURCEMANAGER_H
