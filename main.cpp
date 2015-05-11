#include <iostream>

#ifdef _WIN32

#include <windows.h>

#endif

#include <SDL.h>
#include <DrawingItems/ItemDrawing.hpp>


#include "Engine.hpp"
#include "Box2D/Box2D.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

#ifdef _WIN32

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    auto log = Logger::Get();
    auto initService = make_shared<InitService>(log);
    if (!initService->Init()) {
        exit(-1);
    }

    ///
    auto windowService = make_shared<WidowService>(log);
    auto window = windowService->Create("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                        SCREEN_HEIGHT);
    auto render = window->GetRenderer();


    ///
    string resFolder = "../res/";
    auto systemSettings = make_shared<SystemSettings>();
    systemSettings->set_resFolder(resFolder);
    log->Debug(systemSettings->get_resFolder());
    ///
    ///
    auto texturesResourceManager = make_shared<TexturesResourceManager>(systemSettings, render);
    auto spriteAnimationResourceManager = make_shared<SpriteAnimationResourceManager>(systemSettings, render);
    ///

    shared_ptr<Texture> gBackgroundTexture = texturesResourceManager->getResourse((string) "background.png");
    shared_ptr<Texture> gFooTexture = texturesResourceManager->getResourse((string) "foo.png");

    auto background = make_shared<BackgroundObject>(gBackgroundTexture, FPoint(0, 0));

    auto item = std::make_shared<ItemDrawing>(gFooTexture, FPoint(100, 20), "Boy");

    auto inventoryTexture = texturesResourceManager->getResourse((string) "inventoryCell.png");

    std::map<int, string> items;
    items.insert(std::make_pair<int, string>(0, (string) "inventoryItem.png"));

    auto itemsFactory = make_shared<ItemsFactory>(items, texturesResourceManager);
    auto inventory = make_shared<Inventory>(inventoryTexture, itemsFactory, FPoint(0, 0), 6, 5);

    inventory->AddItemForId(0);
    auto test_font = make_shared<Font>(render, resFolder + "fonts/DejaVuSans.ttf", 40,
                                       FPoint(70, 50)); ////TODO перенести в ресурс менеджер
    test_font->SetText("Тест");

    /// b2World world(b2Vec2(0, -2));
    auto world = make_shared<b2World>(b2Vec2(0, 10.0f));
    Graphic::PhysicDraw *physicDraw = new Graphic::PhysicDraw(100.0f);
    world->SetDebugDraw(physicDraw);
    CollisionDetector collisionDetector;
    world->SetContactListener(&collisionDetector);
    ///
    auto scriptResourceManager = std::make_shared<ScriptResourceManager>(systemSettings);

    auto weaponsManager = make_shared<WeaponsManager>();
    auto gameObjFactory = make_shared<GameObjectsFactory>(texturesResourceManager, spriteAnimationResourceManager,
                                                          scriptResourceManager,
                                                          world, weaponsManager);

    auto notificationServices = make_shared<NotificationServices>();
    notificationServices->RegisterListener("inventoryAdd",
                                           std::bind(&Inventory::AddItemForId, inventory, std::placeholders::_1));
    auto drawDebugEngine = std::make_shared<DrawDebugEngine>(
            make_shared<Font>(render, resFolder + "fonts/DejaVuSans.ttf", 14, FPoint(SCREEN_WIDTH - 200, 10),
                              TTF_STYLE_NORMAL));
    auto _sceneManager = std::make_shared<SceneManager>(world, notificationServices, drawDebugEngine);
     shared_ptr<SceneController> sceneController = make_shared<SceneController>(gameObjFactory);
    _sceneManager->SetController(sceneController);
    auto mapResourceManager = make_shared<MapResourceManager>(_sceneManager, gameObjFactory, systemSettings);
    auto backgroundNode = _sceneManager->AddChildNode("BackGroundNode");
    backgroundNode->AttachObject(background);
    auto mainNode = mapResourceManager->getResourse("Level1");
    if (mainNode == nullptr) {
        log->Error("Map load failed!");
        return 0;
    }

    sceneController->SetTargetNode(mainNode);

    weaponsManager->SetWeapon(gameObjFactory->CreateWeapon(objectId::weaponAkm));

    mainNode->AttachObject(item);

    mainNode->AttachObject(test_font);
    auto hudNode = _sceneManager->AddChildNode("HudNode", true);
    hudNode->AttachObject(inventory);

    auto debugNode = _sceneManager->AddChildNode("DebugNode", true);

    debugNode->AttachObject(drawDebugEngine);
    MainLoop mainLoop(
            _sceneManager); ////TODO Сделать глобальный обработчик клавиш( например чтобы пересоздавать плеера в реалтайме// )

    return mainLoop.Start();
}
