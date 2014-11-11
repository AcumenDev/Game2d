#include "GameLoop.h"

GameLoop::GameLoop(SDL_Renderer* renderer,std::shared_ptr<Texture> backgroundTexture,std::shared_ptr<Player> player) {
    _renderer = renderer;
    _player = player;
    _backgroundTexture = backgroundTexture;
    //ctor
}

GameLoop::~GameLoop() {
    //dtor
}
void GameLoop::Draw() {
    SDL_SetRenderDrawColor( _renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( _renderer );
    _backgroundTexture->render( 0, 0 );
    _player->Draw();
    SDL_RenderPresent( _renderer );
}

void GameLoop::CheckInput() {
    SDL_Event  event;
    if( SDL_PollEvent( &event ) == 0 ) {
        return;
    }

    switch(event.type) {
    case SDL_QUIT : {
        Stop();
        break;
    }
    case SDL_KEYDOWN : {
        std::cout<<"Key press"<<event.key.keysym.sym<<std::endl;
        switch(event.key.keysym.sym) {
        case SDLK_LEFT: {
            _player->ToLeft(_GetDeltaTime());
            break;
        }
        case SDLK_RIGHT: {
            _player->ToRight(_GetDeltaTime());
            break;
        }
        case SDLK_UP: {
            _player->Jump(200);
            break;
        }
        }
    }
    }
}

void GameLoop::Update(float delta) {
    _player->Update(_GetDeltaTime());
}
