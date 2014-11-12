#include "GameLoop.h"

GameLoop::GameLoop(std::shared_ptr<Logger> log, SDL_Renderer* renderer,std::shared_ptr<Texture> backgroundTexture,std::shared_ptr<Player> player) {
    _log = log;
    _renderer = renderer;
    _player = player;
    _backgroundTexture = backgroundTexture;
}

void GameLoop::Draw() {
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
        _log->Debug("Key press: " + std::to_string(event.key.keysym.sym));
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
