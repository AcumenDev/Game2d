#ifdef _WIN32
#include <windows.h>

#endif
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include "ObjectsDrawing/Utils/PhysicDraw.hpp"
#include "Box2D/Box2D.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using std::cout;
using std::endl;

float toScrean(float i){
    return i* 100.0f;
}
float toPhysic(float i){
    return i*0.01f;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
      ///  _log-> Error("SDL could not initialize! SDL Error: "+ std::string(SDL_GetError()));
        return false;
    }

   // int imgFlags  = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
  //  if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
  //      _log-> Error("SDL_image could not initialize! SDL_image Error: "+ std::string(SDL_GetError()));
 //       return false;
 //   }
    SDL_Window *gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


   // SDL_GLContext glContext = SDL_GL_CreateContext(gWindow);
  //  if (glContext == nullptr) {
//  _log-> Error("GLContext could not be created! SDL Error: "+ std::string(SDL_GetError()));

  //  }

    SDL_Renderer * renderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {

        cout<< std::string(SDL_GetError());
    }

    b2Vec2 gravity( 0.0f, -10.0f);

    Graphic::PhysicDraw physicDraw(renderer);
    b2World world(gravity);
    world.SetDebugDraw(&physicDraw);

    float StP =100.0f;

    float xh = 200.0f;
    float yw = 200.0f;

    float corx = 10.0f-xh/2;
    float cory = 10.0f-yw/2;


    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(corx/StP, cory/StP);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(xh/StP, yw/StP);
    groundBody->CreateFixture(&groundBox, 0.0f);


//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(0.0f, 4.0f);
//    b2Body* body = world.CreateBody(&bodyDef);
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(1.0f, 1.0f);
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//    body->CreateFixture(&fixtureDef);



    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;


    bool _run = true;
    while (_run) {

        SDL_Event event;
        if (SDL_PollEvent(&event) == 0) {
            continue;
        }

        switch (event.type) {
            case SDL_QUIT : {
                _run = false;
                break;
            }
        }
        // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      //  SDL_Rect rectangle;

      //  rectangle.x = 0;
      //  rectangle.y = 0;
      //  rectangle.w = 50;
       // rectangle.h = 50;
     //   SDL_RenderFillRect(renderer, &rectangle);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, 10, 10, 10, 200);
        SDL_RenderDrawLine(renderer, 10, 10, 200, 10);
        world.Step(timeStep, velocityIterations, positionIterations);
        world.DrawDebugData();

        SDL_RenderPresent(renderer);
     //   b2Vec2 position = body->GetPosition();
     //   float32 angle = body->GetAngle();
     //   printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
      // fflush(stdout);
    }
}