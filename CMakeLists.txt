cmake_minimum_required(VERSION 2.8.4)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BASE_DIR "D:/my/git_repository/game2d")

SET(OUTPUT_BUILD_DIRECTORY "${BASE_DIR}/build")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BUILD_DIRECTORY})


set(SDL2_HEADERS "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/include/SDL2")
set(SDL2_ttf_HEADERS "${BASE_DIR}/lib/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2")
set(SDL2_image_HEADERS "${BASE_DIR}/lib/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2")

include_directories(
Engine/include
include
${SDL2_HEADERS}
${SDL2_ttf_HEADERS}
${SDL2_image_HEADERS}
)

set(SDL2_LIB "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/lib/libSDL2.dll.a")
set(SDL2Main_LIB "${BASE_DIR}/lib/SDL2-2.0.3/i686-w64-mingw32/lib/libSDL2main.a")
set(SDL2_image_LIB "${BASE_DIR}/lib/SDL2_image-2.0.0/i686-w64-mingw32/lib/libSDL2_image.dll.a")
set(SDL2_ttf_LIB "${BASE_DIR}/lib/SDL2_ttf-2.0.12/i686-w64-mingw32/lib/libSDL2_ttf.dll.a")

add_library(SDL2 STATIC IMPORTED)
set_property(TARGET SDL2 PROPERTY IMPORTED_LOCATION ${SDL2_LIB})

add_library(SDL2Main STATIC IMPORTED)
set_property(TARGET SDL2Main PROPERTY IMPORTED_LOCATION ${SDL2Main_LIB})

add_library(SDL2_image STATIC IMPORTED)
set_property(TARGET SDL2_image PROPERTY IMPORTED_LOCATION ${SDL2_image_LIB})

add_library(SDL2_ttf STATIC IMPORTED)
set_property(TARGET SDL2_ttf PROPERTY IMPORTED_LOCATION ${SDL2_ttf_LIB})


set(HEADER_FILES
    Engine/include/ObjectsDrawing/Inventory/Inventory.hpp
    Engine/include/ObjectsDrawing/Inventory/InventoryItem.hpp
    Engine/include/ObjectsDrawing/Utils/ShowFps.hpp
    Engine/include/ObjectsDrawing/BackgroundObject.hpp
    Engine/include/ObjectsDrawing/Font.hpp
    Engine/include/ObjectsDrawing/Player.hpp
    Engine/include/services/InitService.hpp
    Engine/include/services/NotificationServices.hpp
    Engine/include/services/WidowService.hpp
    Engine/include/Utils/IPoint.hpp
    Engine/include/Utils/IRectangle.hpp
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
    Engine/include/UpdateEventDto.hpp)

set(SOURCE_FILES
    Engine/src/ObjectsDrawing/Inventory/InventoryItem.cpp
    Engine/src/ObjectsDrawing/Inventory/Inventory.cpp
    Engine/src/ObjectsDrawing/Utils/ShowFps.cpp
    Engine/src/ObjectsDrawing/BackgroundObject.cpp
    Engine/src/ObjectsDrawing/Font.cpp
    Engine/src/ObjectsDrawing/Player.cpp
    Engine/src/services/InitService.cpp
    Engine/src/services/NotificationServices.cpp
    Engine/src/services/WidowService.cpp
    Engine/src/Utils/IPoint.cpp
    Engine/src/Utils/IRectangle.cpp
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
    include/DrawingItems/ItemDrawing.hpp
    src/DrawingItems/ItemDrawing.cpp
    main.cpp)

add_executable(${PROJECT_NAME}  ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} SDL2 SDL2Main SDL2_image SDL2_ttf)