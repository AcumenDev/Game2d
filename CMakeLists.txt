cmake_minimum_required(VERSION 2.8.4)
project(Game)

include(../CMakeLists.txt) # SET(BASE_DIR D:/my/git_repository/game2d)

SET(OUTPUT_BUILD_DIRECTORY "${BASE_DIR}/build")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}") #-static-libgcc -static-libstdc++

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})

#SDL2
set(SDL2_HEADERS "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/include/SDL2")
set(SDL2_LIB "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/lib/libSDL2.dll.a")
add_library(SDL2 STATIC IMPORTED)
set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${SDL2_LIB})
#SDL2

#SDL2Main_LIB
set(SDL2Main_LIB "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/lib/libSDL2main.a")
add_library(SDL2Main STATIC IMPORTED)
set_property(TARGET SDL2Main PROPERTY IMPORTED_LOCATION ${SDL2Main_LIB})
#SDL2Main_LIB

#SDL2_image
set(SDL2_image_HEADERS "${BASE_DIR}/lib/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2")
set(SDL2_image_LIB "${BASE_DIR}/lib/SDL2_image-2.0.0/i686-w64-mingw32/lib/libSDL2_image.dll.a")
add_library(SDL2_image STATIC IMPORTED)
set_property(TARGET SDL2_image PROPERTY IMPORTED_LOCATION ${SDL2_image_LIB})
#SDL2_image

#SDL2_ttf
set(SDL2_ttf_HEADERS "${BASE_DIR}/lib/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2")
set(SDL2_ttf_LIB "${BASE_DIR}/lib/SDL2_ttf-2.0.12/i686-w64-mingw32/lib/libSDL2_ttf.dll.a")
add_library(SDL2_ttf STATIC IMPORTED)
set_property(TARGET SDL2_ttf PROPERTY IMPORTED_LOCATION ${SDL2_ttf_LIB})
#SDL2_ttf

#Box2D
set(BOX2D_HEADERS "${BASE_DIR}/lib/Box2D_v2.3.2/include")
set(BOX2D_LIB "${BASE_DIR}/lib/Box2D_v2.3.2/lib/libBox2D.dll.a")
add_library(Box2D STATIC IMPORTED)
set_property(TARGET Box2D PROPERTY IMPORTED_LOCATION ${BOX2D_LIB})
#Box2D

#glew
set(GLEW_HEADERS "${BASE_DIR}/lib/glew-1.11.0/include")
set(GLEW_LIB "${BASE_DIR}/lib/glew-1.11.0/lib/libglew32.dll.a")
add_library(GLEW STATIC IMPORTED)
set_property(TARGET GLEW PROPERTY IMPORTED_LOCATION ${GLEW_LIB})
#glew

#glm
set(GLM_HEADERS "${BASE_DIR}/lib/glm-0.9.6.1/include")
set(GLM_LIB "${BASE_DIR}/lib/glm-0.9.6.1/lib/libglm_shared.dll.a")
add_library(GLM STATIC IMPORTED)
set_property(TARGET GLM PROPERTY IMPORTED_LOCATION ${GLM_LIB})
#glm

#rapidjson
set(RAPIDJSON_HEADERS "${BASE_DIR}/lib/rapidjson/include")
#rapidjson

#Lua
set(LUA_HEADERS "${BASE_DIR}/lib/lua-5.1.5/include")
set(LUA_LIB "${BASE_DIR}/lib/lua-5.1.5/liblua5.1.a")
add_library(LUA STATIC IMPORTED)
set_property(TARGET LUA PROPERTY IMPORTED_LOCATION ${LUA_LIB})
#Lua

#LuaBridge
set(LUABRIDGE_HEADERS "${BASE_DIR}/lib/LuaBridge")
#LuaBridge

include_directories(
Engine/include
include
${SDL2_HEADERS}
${SDL2_ttf_HEADERS}
${SDL2_image_HEADERS}
${BOX2D_HEADERS}
${GLEW_HEADERS}
${GLM_HEADERS}
${RAPIDJSON_HEADERS}
${LUABRIDGE_HEADERS}
${LUA_HEADERS}
)

set(HEADER_FILES_ENGINE
    Engine/include/ObjectsDrawing/Inventory/Inventory.hpp
    Engine/include/ObjectsDrawing/Inventory/InventoryItem.hpp
    Engine/include/ObjectsDrawing/Utils/PhysicDraw.hpp
    Engine/include/ObjectsDrawing/BackgroundObject.hpp
    Engine/include/ObjectsDrawing/Font.hpp
    Engine/include/services/InitService.hpp
    Engine/include/services/NotificationServices.hpp
    Engine/include/services/WidowService.hpp
    Engine/include/Utils/Point.hpp
    Engine/include/Utils/Rectangle.hpp
    Engine/include/DrawingObject.hpp
    Engine/include/Engine.hpp
    Engine/include/EventInputSystem.hpp
    Engine/include/Utils/logger/Logger.hpp
    Engine/include/MainLoop.hpp
    Engine/include/SceneManager.hpp
    Engine/include/SceneNode.hpp
    Engine/include/SelectableDrawingObject.hpp
    Engine/include/SpriteAnimation.hpp
    Engine/include/Texture.hpp
    Engine/include/Window.hpp
    Engine/include/ItemsFactory.hpp
    Engine/include/UpdateEventDto.hpp
    Engine/include/ObjectBase.hpp
    Engine/include/physics/CollisionDetector.hpp
    Engine/include/physics/BasePhysicBody.hpp
    Engine/include/physics/PlayerPhysic.hpp
    Engine/include/physics/BoundPhysic.hpp
    Engine/include/gameObjects/Player.hpp
    Engine/include/gameObjects/GameObjectBase.hpp
    Engine/include/gameObjects/GameObjectsFactory.hpp
    Engine/include/gameObjects/Bound.hpp
    Engine/include/gameObjects/AnimationObject.hpp
    Engine/include/gameObjects/weapons/WeaponBase.hpp
    Engine/include/gameObjects/weapons/Akm.hpp
    Engine/include/ObjectsDrawing/PlayerGraphic.hpp
    Engine/include/ObjectsDrawing/ObjectDrawingBase.hpp
    Engine/include/ObjectsDrawing/TextureDrawing.hpp
    Engine/include/ObjectsDrawing/SpriteAnimationDrawing.hpp
    Engine/include/ObjectsDrawing/Utils/DrawDebugEngine.hpp
    Engine/include/resourceManagers/BaseResourceManager.hpp
    Engine/include/resourceManagers/SpriteAnimationResourceManager.hpp
    Engine/include/resourceManagers/TexturesResourceManager.hpp
    Engine/include/resourceManagers/ScriptResourceManager.hpp
    Engine/include/resourceManagers/MapResourceManager.hpp
    Engine/include/settings/SystemSettings.hpp
    Engine/include/Utils/fileSystem/FileSystemUtils.hpp
    Engine/include/render/Camera.hpp
    Engine/include/render/Render.hpp
    Engine/include/Utils/debugEngine/DebugEngineBase.hpp
    Engine/include/Utils/debugEngine/TraceEngineUtils.hpp
    Engine/include/scriptBinding/Script.hpp
    Engine/include/scriptBinding/PlayerScript.hpp
    Engine/include/scriptBinding/BaseScriptBinding.hpp
    Engine/include/scriptBinding/BoundScript.hpp
    Engine/include/scriptBinding/weapons/AkmScript.hpp
    Engine/include/gameManagers/WeaponsManager.hpp
)

set(SOURCE_FILES_ENGINE
    Engine/src/ObjectsDrawing/Inventory/InventoryItem.cpp
    Engine/src/ObjectsDrawing/Inventory/Inventory.cpp
    Engine/src/ObjectsDrawing/BackgroundObject.cpp
    Engine/src/ObjectsDrawing/Font.cpp
    Engine/src/services/InitService.cpp
    Engine/src/services/NotificationServices.cpp
    Engine/src/services/WidowService.cpp
    Engine/src/DrawingObject.cpp
    Engine/src/EventInputSystem.cpp
    Engine/src/utils/logger/Logger.cpp
    Engine/src/MainLoop.cpp
    Engine/src/SceneManager.cpp
    Engine/src/SceneNode.cpp
    Engine/src/SelectableDrawingObject.cpp
    Engine/src/SpriteAnimation.cpp
    Engine/src/Texture.cpp
    Engine/src/Window.cpp
    Engine/src/ItemsFactory.cpp
    Engine/src/UpdateEventDto.cpp
    Engine/src/physics/CollisionDetector.cpp
    Engine/src/physics/BasePhysicBody.cpp
    Engine/src/physics/PlayerPhysic.cpp
    Engine/src/physics/BoundPhysic.cpp
    Engine/src/gameObjects/GameObjectsFactory.cpp
    Engine/src/gameObjects/Player.cpp
    Engine/src/gameObjects/Bound.cpp
    Engine/src/gameObjects/AnimationObject.cpp
    Engine/src/gameObjects/weapons/Akm.cpp
    Engine/src/ObjectsDrawing/PlayerGraphic.cpp
    Engine/src/ObjectsDrawing/TextureDrawing.cpp
    Engine/src/ObjectsDrawing/SpriteAnimationDrawing.cpp
    Engine/src/ObjectsDrawing/Utils/PhysicDraw.cpp
    Engine/src/ObjectsDrawing/Utils/DrawDebugEngine.cpp
    Engine/src/resourceManagers/SpriteAnimationResourceManager.cpp
    Engine/src/resourceManagers/TexturesResourceManager.cpp
    Engine/src/resourceManagers/ScriptResourceManager.cpp
    Engine/src/resourceManagers/MapResourceManager.cpp
    Engine/src/render/Camera.cpp
    Engine/src/render/Render.cpp
    Engine/src/ObjectsDrawing/Utils/debugEngine/TraceEngineUtils.cpp
    Engine/src/scriptBinding/Script.cpp
    Engine/src/scriptBinding/PlayerScript.cpp
    Engine/src/scriptBinding/BaseScriptBinding.cpp
    Engine/src/scriptBinding/BoundScript.cpp
    Engine/src/scriptBinding/weapons/AkmScript.cpp
    )

set(HEADER_FILES_GAME
    include/DrawingItems/ItemDrawing.hpp
    )

set(SOURCE_FILES_GAME
    src/DrawingItems/ItemDrawing.cpp
    main.cpp
    )

add_executable(${PROJECT_NAME}  ${SOURCE_FILES_ENGINE} ${SOURCE_FILES_GAME}  ${HEADER_FILES_ENGINE}  ${HEADER_FILES_GAME} Engine/include/scriptBinding/BoundScript.hpp Engine/include/scriptBinding/BoundScript.hpp)
target_link_libraries(${PROJECT_NAME} SDL2 SDL2Main SDL2_image SDL2_ttf Box2D LUA)


add_executable(test_box2d test/test_box2d.cpp)
target_link_libraries(test_box2d Box2D)

add_executable(test_openGl_3 test/OpenGl/rectangle_shaders/test_openGl_3.cpp)
target_link_libraries(test_openGl_3 SDL2 SDL2Main  opengl32 GLEW GLM )

add_executable(test_sdl2_box2d test/sdl2_box2d/sdl2_box2d.cpp
 ${SOURCE_FILES_ENGINE} ${HEADER_FILES_ENGINE} Engine/src/scriptBinding/BoundScript.hpp Engine/src/scriptBinding/BoundScript.cpp)
target_link_libraries(test_sdl2_box2d SDL2 SDL2Main SDL2_image SDL2_ttf  Box2D)

