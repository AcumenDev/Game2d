#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "Texture.hpp"
#include "Logger.hpp"
#include <memory>
class ResourceManager {
public:
    ResourceManager(std::shared_ptr<Logger> log, SDL_Renderer* render);
    virtual ~ResourceManager();
    std::shared_ptr<Texture> GetTextureFromFile(std::string path);
protected:
private:
    SDL_Renderer* _render;
    std::shared_ptr<Logger> _log;
    std::string _name;
};

#endif // RESOURCEMANAGER_H
