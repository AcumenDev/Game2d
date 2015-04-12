#include <resourceManagers/SpriteAnimationResourceManager.hpp>

SpriteAnimationResourceManager::SpriteAnimationResourceManager(shared_ptr<SystemSettings> systemSettings, SDL_Renderer *render) {
    _name = "SpriteAnimationResourceManager";
    _systemSettings = systemSettings;
    _render = render;
}

shared_ptr<SpriteAnimation> SpriteAnimationResourceManager::getResourse(string name) {
    auto path = _systemSettings->GetSpriteAnimationPath(name);
    Logger::Get()->Debug(_name,"Loading sprite animations from: "+ path);
    std::ifstream spriteAnimation(path.c_str());
    if (!spriteAnimation.is_open()) {
        Logger::Get()->Error(_name, "Couldn't load the spriteAnimaton file : " + path);
        return nullptr;
    }
    std::string jsonString = string((std::istreambuf_iterator<char>(spriteAnimation)), (std::istreambuf_iterator<char>()));

    map<string, SpriteSeries> spriteSeries;
    Document d;
    d.Parse<ParseFlag::kParseDefaultFlags>(jsonString.c_str());
    string nameResFile = d["resFile"].GetString();

    string resFile = _systemSettings->GetTexturePath(nameResFile);

    Logger::Get()->Debug(_name, "Loaded textures from file: " + resFile);
    SDL_Surface *surface = IMG_Load(resFile.c_str());

    if (surface == nullptr) {
        Logger::Get()->Error(_name, "Unable to load image " + resFile + " SDL_image Error: " + IMG_GetError());

    }

    const Value &a = d["series"];

    for (SizeType i = 0; i < a.Size(); i++) {
        vector<shared_ptr<Texture>> result_sprites;
        string nameSeries = a[i]["name"].GetString();
        double animationSpeed = a[i]["animationSpeed"].GetDouble();

        Logger::Get()->Debug(_name, "Series: " + nameSeries + " animation speed: " + std::to_string(animationSpeed));

        const Value &textures = a[i]["textures"];
        for (SizeType u = 0; u < textures.Size(); u++) {

            int x = textures[u]["x"].GetInt();
            int y = textures[u]["y"].GetInt();
            int h = textures[u]["h"].GetInt();
            int w = textures[u]["w"].GetInt();

            SDL_Surface *surfaceTemp = SDL_CreateRGBSurface(0, w, h,
                    surface->format->BitsPerPixel,
                    surface->format->Rmask,
                    surface->format->Gmask,
                    surface->format->Bmask,
                    surface->format->Amask
            );

            SDL_Rect sdl_rect;
            sdl_rect.x = x;
            sdl_rect.y = y;
            sdl_rect.h = h;
            sdl_rect.w = w;

            SDL_BlitSurface(surface, &sdl_rect, surfaceTemp, NULL);

            SDL_Texture *sdl_texture = SDL_CreateTextureFromSurface(_render, surfaceTemp);
            int _w, _h;
            SDL_QueryTexture(sdl_texture, NULL, NULL, &_w, &_h);
            std::shared_ptr<Texture> texture = std::make_shared<Texture>(_render, sdl_texture, _w, _h);
            result_sprites.push_back(texture);

            SDL_FreeSurface(surfaceTemp);
        }
        Logger::Get()->Debug(_name, "Textures loaded: " + std::to_string(textures.Size()));
        spriteSeries.insert(std::make_pair<string, SpriteSeries>(string(nameSeries), SpriteSeries(result_sprites, animationSpeed)));
    }

    return std::make_shared<SpriteAnimation>(spriteSeries);
}