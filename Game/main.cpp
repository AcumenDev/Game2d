#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "ItemDrawing.hpp"

#include "Engine.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    auto log = std::make_shared<Logger>();
    auto initService = std::make_shared<InitService>(log);
    if(!initService->Init()) {
        exit(-1);
    }

    auto windowService = std::make_shared<WidowService>(log);
    auto window = windowService->Create("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);
    auto render = window->GetRenderer();
    ResourceManager resourceManager(log);
    std::string resFolder = "../../res/";
    std::shared_ptr<Texture> gBackgroundTexture = resourceManager.GetTextureFromFile(render,resFolder+"background.png");
    std::shared_ptr<Texture> gFooTexture = resourceManager.GetTextureFromFile(render,resFolder+"foo.png");
    std::shared_ptr<Texture> gFooTexture1 = resourceManager.GetTextureFromFile(render,resFolder+"foo1.png");

    std::vector<std::shared_ptr<Texture>> texstures = {gFooTexture, gFooTexture1};

    auto background = std::make_shared<BackgroundObject>(log,gBackgroundTexture,IPoint(0,0));
    auto player = std::make_shared<Player>(log,gFooTexture,IPoint(240, 190));
    auto item=std::make_shared<ItemDrawing>(log,gFooTexture,IPoint(100,20));

    player->Init(std::make_shared<SpriteAnimation>(texstures, 0.05));
   // player->SetPosition(IPoint(240, 190));


    auto _sceneManager = std::make_shared<SceneManager>(log, render);
    auto mainNode =  _sceneManager->AddChildNode("MainNode");
    mainNode->AttachObject(background);
    mainNode->AttachObject(player);
    mainNode->AttachObject(item);
    MainLoop mainLoop(_sceneManager, log);

    mainLoop.Start();
    return 0;
}
