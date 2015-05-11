#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include "settings/SystemSettings.hpp"

#include "Utils/Point.hpp"
#include "Utils/Rectangle.hpp"

#include "Texture.hpp"

#include "SpriteAnimation.hpp"
#include "MainLoop.hpp"
#include "Window.hpp"

#include "resourceManagers/TexturesResourceManager.hpp"
#include "resourceManagers/SpriteAnimationResourceManager.hpp"
#include "resourceManagers/ScriptResourceManager.hpp"
#include "resourceManagers/MapResourceManager.hpp"
#include "DrawingObject.hpp"

#include "EventInputSystem.hpp"

#include "SelectableDrawingObject.hpp"

#include "physics/PlayerPhysic.hpp"
#include "physics/BasePhysicBody.hpp"
#include "physics/CollisionDetector.hpp"

#include "gameObjects/Player.hpp"
#include "gameObjects/GameObjectBase.hpp"
#include "gameObjects/GameObjectsFactory.hpp"
#include "gameObjects/AnimationObject.hpp"
#include "gameObjects/Bound.hpp"
#include "gameObjects/weapons/WeaponBase.hpp"
#include "gameObjects/weapons/Akm.hpp"

#include "ObjectsDrawing/ObjectDrawingBase.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"
#include "ObjectsDrawing/TextureDrawing.hpp"
#include "ObjectsDrawing/BackgroundObject.hpp"
#include "ObjectsDrawing/Inventory/Inventory.hpp"
#include "ObjectsDrawing/Font.hpp"
#include "ObjectsDrawing/SpriteAnimationDrawing.hpp"
#include "ObjectsDrawing/Utils/PhysicDraw.hpp"


#include "render/Camera.hpp"
#include "render/Render.hpp"


#include "services/WidowService.hpp"
#include "services/InitService.hpp"

#include "scriptBinding/Script.hpp"
#include "scriptBinding/PlayerScript.hpp"
#include "scriptBinding/weapons/AkmScript.hpp"


#include "ObjectsDrawing/Utils/DrawDebugEngine.hpp"

#include "gameManagers/WeaponsManager.hpp"
#include "scene/SceneController.hpp"


#endif // ENGINE_HPP_INCLUDED
