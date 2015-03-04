#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <settings/SystemSettings.hpp>

#include "Utils/Point.hpp"
#include "Utils/Rectangle.hpp"

#include "Texture.hpp"
#include "resourceManagers/TexturesResourceManager.hpp"
#include "SpriteAnimation.hpp"
#include "MainLoop.hpp"
#include "Window.hpp"

#include <resourceManagers/SpriteAnimationResourceManager.hpp>

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

#include "ObjectsDrawing/ObjectDrawingBase.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"
#include "ObjectsDrawing/TextureDrawing.hpp"
#include "ObjectsDrawing/BackgroundObject.hpp"
#include "ObjectsDrawing/Inventory/Inventory.hpp"
#include "ObjectsDrawing/Font.hpp"
#include "ObjectsDrawing/SpriteAnimationDrawing.hpp"
#include "ObjectsDrawing/Utils/ShowFps.hpp"
#include "ObjectsDrawing/Utils/PhysicDraw.hpp"


#include "render/Camera.hpp"

#include "services/WidowService.hpp"
#include "services/InitService.hpp"


#endif // ENGINE_HPP_INCLUDED
