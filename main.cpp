#include <iostream>

#ifdef _WIN32

#include <windows.h>

#endif

#include <SDL.h>
#include <DrawingItems/ItemDrawing.hpp>
#include <ObjectsDrawing/Utils/DrawDebugEngine.hpp>

#include "Engine.hpp"
#include "Box2D/Box2D.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#ifdef _WIN32

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    auto log = Logger::Get();
    auto initService = std::make_shared<InitService>(log);
    if (!initService->Init()) {
        exit(-1);
    }

    auto windowService = std::make_shared<WidowService>(log);
    auto window = windowService->Create("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                        SCREEN_HEIGHT);
    auto render = window->GetRenderer();
    Render::Init(render, make_shared<Camera>()); //todo Убрать в виндов сервис
    auto resourceManager = std::make_shared<TexturesResourceManager>(render);
    std::string resFolder = "../res/";

    auto systemSettings = std::make_shared<SystemSettings>();
    systemSettings->set_resFolder(resFolder);
    log->Debug(systemSettings->get_resFolder());
    std::shared_ptr<Texture> gBackgroundTexture = resourceManager->getResourse(resFolder + "background.png");
    std::shared_ptr<Texture> gFooTexture = resourceManager->getResourse(resFolder + "foo.png");

    auto spriteAnimationResourceManager = make_shared<SpriteAnimationResourceManager>(systemSettings, render);

    auto sA = spriteAnimationResourceManager->getResourse(string("player.json"));
    auto sAFire = spriteAnimationResourceManager->getResourse(string("fire.json"));
    auto fireAnimation = std::make_shared<SpriteAnimationDrawing>(sAFire);
    fireAnimation->SetPosition(FPoint(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    auto fireAnimationObject = make_shared<AnimationObject>(fireAnimation);

    auto background = std::make_shared<BackgroundObject>(gBackgroundTexture, FPoint(0, 0));

    auto item = std::make_shared<ItemDrawing>(gFooTexture, FPoint(100, 20), "Boy");

    auto inventoryTexture = resourceManager->getResourse(resFolder + "inventoryCell.png");

    std::map<int, std::string> items;
    items.insert(std::make_pair<int, std::string>(0, std::string(resFolder + "inventoryItem.png")));

    auto itemsFactory = std::make_shared<ItemsFactory>(items, resourceManager);
    auto inventory = std::make_shared<Inventory>(inventoryTexture, itemsFactory, FPoint(0, 0), 6, 5);

    //  auto inventoryItem =  std::make_shared<InventoryItem>(1, inventoryItemTexture);
    inventory->AddItemForId(0);
    auto test_font = std::make_shared<Font>(render, resFolder + "fonts/DejaVuSans.ttf", 40, FPoint(70, 50));
    test_font->SetText("Тест");

    // b2World world(b2Vec2(0, -2));
    auto world = std::make_shared<b2World>(b2Vec2(0, 10.0f));

    Graphic::PhysicDraw *physicDraw = new Graphic::PhysicDraw(100.0f);
    world->SetDebugDraw(physicDraw);

    CollisionDetector collisionDetector;

    world->SetContactListener(&collisionDetector);

    ///New player
    auto playerPhysic = std::make_shared<PlayerPhysic>(world, gFooTexture->getWidth(), gFooTexture->getHeight(),
                                                       FPoint(100, 100));
    auto playerGraphic = std::make_shared<PlayerGraphic>(sA, log);
    auto playerNew = std::make_shared<Player>(log, playerPhysic, playerGraphic);
    ///New player

    //Bound
    auto boundTexture = resourceManager->getResourse(resFolder + "Bound.png");
    auto boundGrapphic = std::make_shared<TextureDrawing>(boundTexture);
    auto boundPhysic = std::make_shared<BoundPhysic>(world, boundTexture->getWidth() + 1000, boundTexture->getHeight(),
                                                     FPoint(0, 400));
    auto bound = std::make_shared<Bound>(boundGrapphic, boundPhysic);
    //Bound

    auto notificationServices = std::make_shared<NotificationServices>();
    notificationServices->RegisterListener("inventoryAdd",
                                           std::bind(&Inventory::AddItemForId, inventory, std::placeholders::_1));
    auto drawDebugEngine = std::make_shared<DrawDebugEngine>(
            make_shared<Font>(render, resFolder + "fonts/DejaVuSans.ttf", 14, FPoint(SCREEN_WIDTH - 200, 10),
                              TTF_STYLE_NORMAL));
    auto _sceneManager = std::make_shared<SceneManager>(render, world, notificationServices, drawDebugEngine);

    auto backgroundNode = _sceneManager->AddChildNode("BackGroundNode");
    backgroundNode->AttachObject(background);
    auto mainNode = _sceneManager->AddChildNode("MainNode");

    mainNode->AttachObject(bound);

    mainNode->AttachObject(fireAnimationObject);
    mainNode->AttachObject(playerNew);
    mainNode->AttachObject(item);

    mainNode->AttachObject(test_font);
    auto hudNode = _sceneManager->AddChildNode("HudNode", true);
    hudNode->AttachObject(inventory);

    auto debugNode = _sceneManager->AddChildNode("DebugNode", true);

    debugNode->AttachObject(drawDebugEngine);
    MainLoop mainLoop(_sceneManager);
    mainLoop.Start();
    return 0;
}
