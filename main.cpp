#include <iostream>

#ifdef _WIN32
#include <windows.h>

#endif
#include <SDL.h>
#include <DrawingItems/ItemDrawing.hpp>

#include "Engine.hpp"
#include "Box2D/Box2D.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    auto log = std::make_shared<Logger>();
    auto initService = std::make_shared<InitService>(log);
    if (!initService->Init()) {
        exit(-1);
    }

    auto windowService = std::make_shared<WidowService>(log);
    auto window = windowService->Create("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);
    auto render = window->GetRenderer();
    auto resourceManager = std::make_shared<ResourceManager>(log, render);
    std::string resFolder = "../res/";
    std::shared_ptr<Texture> gBackgroundTexture = resourceManager->GetTextureFromFile(resFolder + "background.png");
    std::shared_ptr<Texture> gFooTexture = resourceManager->GetTextureFromFile(resFolder + "foo.png");
    std::shared_ptr<Texture> gFooTexture1 = resourceManager->GetTextureFromFile(resFolder + "foo1.png");

    std::vector<std::shared_ptr<Texture>> texstures = {gFooTexture, gFooTexture1};

    auto background = std::make_shared<BackgroundObject>(log, gBackgroundTexture, FPoint(0, 0));
    auto player = std::make_shared<PlayerOld>(log, gFooTexture, FPoint(240, 190));
    auto item = std::make_shared<ItemDrawing>(log, gFooTexture, FPoint(100, 20), "Boy");

    auto inventoryTexture = resourceManager->GetTextureFromFile(resFolder + "inventoryCell.png");
    //   auto inventoryItemTexture = resourceManager->GetTextureFromFile(resFolder+"inventoryItem.png");

    std::map<int, std::string> items;
    items.insert(std::make_pair<int, std::string>(0, std::string(resFolder + "inventoryItem.png")));

    auto itemsFactory = std::make_shared<ItemsFactory>(log, items, resourceManager);
    auto inventory = std::make_shared<Inventory>(log, inventoryTexture, itemsFactory, FPoint(0, 0), 6, 5);

    //  auto inventoryItem =  std::make_shared<InventoryItem>(1, inventoryItemTexture);
    inventory->AddItemForId(0);
    auto test_font = std::make_shared<Font>(log, render, resFolder + "fonts/DejaVuSans.ttf", 40, FPoint(70, 50));
    test_font->SetText("Тест");
    auto sAnimation = std::make_shared<SpriteAnimation>(texstures, 0.05);
    //Old Player
    player->Init(sAnimation);
    //Old Player

    ///New player
   // b2World world(b2Vec2(0, -2));
   auto world = std::make_shared<b2World>(b2Vec2(0, 10.0f));

    Graphic::PhysicDraw * physicDraw = new Graphic::PhysicDraw(render,100.0f);
    world->SetDebugDraw(physicDraw);


    auto playerPhysic = std::make_shared<PlayerPhysic>(world, gFooTexture->getWidth(), gFooTexture->getHeight(), FPoint(100, 100));
    auto sAnimationNew = std::make_shared<SpriteAnimation>(texstures, 0.05);
    auto playerGraphic = std::make_shared<PlayerGraphic>(sAnimationNew, log);
    auto playerNew = std::make_shared<Player>(log, playerPhysic, playerGraphic);
    ///New player
    //Bound
    auto boundTexture = resourceManager->GetTextureFromFile(resFolder + "Bound.png");
//
   auto boundGrapphic = std::make_shared<TextureDrawing>(boundTexture);
//
   auto boundPhysic = std::make_shared<BoundPhysic>(world, boundTexture->getHeight(),boundTexture->getWidth(),FPoint(0,400));
//
   auto bound = std::make_shared<Bound>(boundGrapphic, boundPhysic);

    //Bound


    auto notificationServices = std::make_shared<NotificationServices>();
    notificationServices->RegisterListener("inventoryAdd", std::bind(&Inventory::AddItemForId, inventory, std::placeholders::_1));
    auto _sceneManager = std::make_shared<SceneManager>(log, render,world, notificationServices);
    auto mainNode = _sceneManager->AddChildNode("MainNode");

    mainNode->AttachObject(bound);
    mainNode->AttachObject(background);
    mainNode->AttachObject(player);
    mainNode->AttachObject(playerNew);
    mainNode->AttachObject(item);
    mainNode->AttachObject(inventory);
    mainNode->AttachObject(test_font);
    auto debugNode = _sceneManager->AddChildNode("DebugNode");
    auto fps = std::make_shared<ShowFps>(log, render, resFolder + "fonts/DejaVuSans.ttf", 40, FPoint(SCREEN_WIDTH - 100, 10));
    _sceneManager->SetFpsListener(fps);
    debugNode->AttachObject(fps);
    MainLoop mainLoop(_sceneManager, log);
    mainLoop.Start();
    return 0;
}
