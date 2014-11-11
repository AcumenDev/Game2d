#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Engine.hpp"
#include "SDL.h"
#include <iostream>
class GameLoop : public MainLoop {
public:
    GameLoop(SDL_Renderer* renderer, std::shared_ptr<Texture> backgroundTexture,std::shared_ptr<Player> player);
    virtual ~GameLoop();
    void Draw() override;
    void CheckInput()override;
    void Update(float delta) override;
protected:
private:
    SDL_Renderer* _renderer;
    std::shared_ptr<Player> _player;
    std::shared_ptr<Texture> _backgroundTexture;
};

#endif // GAMELOOP_H
