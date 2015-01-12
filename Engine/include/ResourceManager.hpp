#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <memory>
#include <vector>
#include "Utils/Rectangle.hpp"
#include "Texture.hpp"
#include "Logger.hpp"


using std::vector;
using std::shared_ptr;
using std::string;
class ResourceManager {
public:
    ResourceManager(shared_ptr<Logger> log, SDL_Renderer *render);
    virtual ~ResourceManager();
    shared_ptr<Texture> GetTextureFromFile(string path);
    vector<shared_ptr<Texture>> GetTexturesFromFile(string path, vector<FRectangle> rectangls);
protected:
private:
    SDL_Renderer *_render;
    std::shared_ptr<Logger> _log;
    std::string _name;
};

#endif // RESOURCEMANAGER_H
