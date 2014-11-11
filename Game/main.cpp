#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Engine.hpp"

#include "GameLoop.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;



bool init() {

    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        std::cout<<"SDL could not initialize! SDL Error: %s\n"<< SDL_GetError();
        success = false;
    } else {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
            std::cout<<"Warning: Linear texture filtering not enabled!";
        }

        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL ) {
            std::cout<<"Window could not be created! SDL Error: %s\n"<< SDL_GetError();
            success = false;
        } else {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL ) {
                std::cout<<"Renderer could not be created! SDL Error: %s\n"<< SDL_GetError() ;
                success = false;
            } else {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    std::cout<<"SDL_image could not initialize! SDL_image Error: %s\n"<< IMG_GetError();
                    success = false;
                }
            }
        }
    }
//    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    return success;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    if( !init() ) {
        std::cout<<"Failed to initialize!\n" ;
    } else {

        ResourceManager resourceManager;
        std::string resFolder = "../../res/";
        std::shared_ptr<Texture> gBackgroundTexture = resourceManager.GetTextureFromFile(gRenderer,resFolder+"background.png");
        std::shared_ptr<Texture> gFooTexture = resourceManager.GetTextureFromFile(gRenderer,resFolder+"foo.png");
        std::shared_ptr<Texture> gFooTexture1 = resourceManager.GetTextureFromFile(gRenderer,resFolder+"foo1.png");

        std::vector<std::shared_ptr<Texture>> texstures = {gFooTexture, gFooTexture1};

        std::shared_ptr<SpriteAnimation>  spriteAnimation = std::make_shared<SpriteAnimation>(texstures, 0.1);
        std::shared_ptr<Player> player = std::make_shared<Player>();

        player->Init(spriteAnimation);
        player->SetPosition(240, 190);

        GameLoop gameLoop(gRenderer, gBackgroundTexture, player);

        gameLoop.Start();
    }
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
    return 0;
}
