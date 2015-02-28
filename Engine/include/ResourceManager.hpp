#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <memory>
#include <vector>
#include "Utils/Rectangle.hpp"
#include "Texture.hpp"
#include "utils/logger/Logger.hpp"


using std::vector;
using std::shared_ptr;
using std::string;
//TODO Обобщить класс
class ResourceManager {
public:
    ResourceManager(shared_ptr<Logger> log, SDL_Renderer *render);
    virtual ~ResourceManager();
    shared_ptr<Texture> GetTextureFromFile(string path);
    vector<shared_ptr<Texture>> GetTexturesFromFile(string path, vector<IRectangle> rectangls);
protected:
private:
    SDL_Surface * loadSurfaceFromFile(string path);
    SDL_Renderer *_render;
    std::shared_ptr<Logger> _log;
    std::string _name;
};

#endif // RESOURCEMANAGER_H
