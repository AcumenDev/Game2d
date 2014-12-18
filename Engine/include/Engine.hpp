#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include "Utils/IPoint.hpp"
#include "Utils/FPoint.hpp"
#include "Utils/FRectangle.hpp"

#include "Texture.hpp"
#include "ResourceManager.hpp"
#include "SpriteAnimation.hpp"
#include "MainLoop.hpp"
#include "Window.hpp"

#include "DrawingObject.hpp"

#include "EventInputSystem.hpp"

#include "SelectableDrawingObject.hpp"

#include "physics/PlayerPhysic.hpp"
#include "physics/BasePhysicBody.hpp"
#include "physics/CollisionDetector.hpp"

#include "gameObjects/Player.hpp"
#include "gameObjects/GameObjectBase.hpp"
#include "gameObjects/GameObjectsFactory.hpp"
#include "gameObjects/Bound.hpp"

#include "ObjectsDrawing/ObjectDrawingBase.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"
#include "ObjectsDrawing/TextureDrawing.hpp"
#include "ObjectsDrawing/BackgroundObject.hpp"
#include "ObjectsDrawing/PlayerOld.hpp"
#include "ObjectsDrawing/Inventory/Inventory.hpp"
#include "ObjectsDrawing/Font.hpp"
#include "ObjectsDrawing/Utils/ShowFps.hpp"



#include "services/WidowService.hpp"
#include "services/InitService.hpp"


#endif // ENGINE_HPP_INCLUDED
