cmake_minimum_required(VERSION 2.8.4)
project(Game)

SET(BASE_DIR D:/my/git_repository/game2d)

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

include_directories(
Engine/include
include
${SDL2_HEADERS}
${SDL2_ttf_HEADERS}
${SDL2_image_HEADERS}
${BOX2D_HEADERS}
${GLEW_HEADERS}
${GLM_HEADERS}
)

set(HEADER_FILES_ENGINE
    Engine/include/ObjectsDrawing/Inventory/Inventory.hpp
    Engine/include/ObjectsDrawing/Inventory/InventoryItem.hpp
    Engine/include/ObjectsDrawing/Utils/ShowFps.hpp
    Engine/include/ObjectsDrawing/BackgroundObject.hpp
    Engine/include/ObjectsDrawing/Font.hpp
    Engine/include/ObjectsDrawing/PlayerOld.hpp
    Engine/include/services/InitService.hpp
    Engine/include/services/NotificationServices.hpp
    Engine/include/services/WidowService.hpp
    Engine/include/Utils/IPoint.hpp
    Engine/include/Utils/FPoint.hpp
    Engine/include/Utils/FRectangle.hpp
    Engine/include/Utils/SceneManagerFpsCounterBase.hpp
    Engine/include/DrawingObject.hpp
    Engine/include/Engine.hpp
    Engine/include/EventInputSystem.hpp
    Engine/include/Logger.hpp
    Engine/include/MainLoop.hpp
    Engine/include/ResourceManager.hpp
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
    Engine/include/gameObjects/Bound.hpp
    Engine/include/ObjectsDrawing/PlayerGraphic.hpp
    Engine/include/ObjectsDrawing/ObjectDrawingBase.hpp
    Engine/include/ObjectsDrawing/TextureDrawing.hpp
)

set(SOURCE_FILES_ENGINE
    Engine/src/ObjectsDrawing/Inventory/InventoryItem.cpp
    Engine/src/ObjectsDrawing/Inventory/Inventory.cpp
    Engine/src/ObjectsDrawing/Utils/ShowFps.cpp
    Engine/src/ObjectsDrawing/BackgroundObject.cpp
    Engine/src/ObjectsDrawing/Font.cpp
    Engine/src/ObjectsDrawing/PlayerOld.cpp
    Engine/src/services/InitService.cpp
    Engine/src/services/NotificationServices.cpp
    Engine/src/services/WidowService.cpp
    Engine/src/Utils/IPoint.cpp
    Engine/src/Utils/FRectangle.cpp
    Engine/src/DrawingObject.cpp
    Engine/src/EventInputSystem.cpp
    Engine/src/Logger.cpp
    Engine/src/MainLoop.cpp
    Engine/src/ResourceManager.cpp
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
    Engine/src/gameObjects/Player.cpp
    Engine/src/gameObjects/Bound.cpp
    Engine/src/ObjectsDrawing/PlayerGraphic.cpp
    Engine/src/ObjectsDrawing/TextureDrawing.cpp
    )

set(HEADER_FILES_GAME
    include/DrawingItems/ItemDrawing.hpp
    )

set(SOURCE_FILES_GAME
    src/DrawingItems/ItemDrawing.cpp
    main.cpp
    )

add_executable(${PROJECT_NAME}  ${SOURCE_FILES_ENGINE} ${SOURCE_FILES_GAME}  ${HEADER_FILES_ENGINE}  ${HEADER_FILES_GAME})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2Main SDL2_image SDL2_ttf Box2D)


add_executable(test_box2d test_box2d.cpp)
target_link_libraries(test_box2d Box2D)

add_executable(test_openGl_3 test/OpenGl/rectangle_shaders/test_openGl_3.cpp)
target_link_libraries(test_openGl_3 SDL2 SDL2Main  opengl32 GLEW GLM )