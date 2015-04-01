#ifdef _WIN32
#include <windows.h>

#endif
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include <render/Camera.hpp>
#include <render/Render.hpp>
#include "ObjectsDrawing/Utils/PhysicDraw.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using std::cout;
using std::endl;

float StP = 100.0f;

float toScrean(float i) {
    return i * StP;
}
float toPhysic(float i) {
    return i / StP;
}
struct UserData {
    bool IsGround;
};


class ContactListener : public b2ContactListener {

public:
    virtual void BeginContact(b2Contact *contact) override;
    virtual void EndContact(b2Contact *contact) override;
};

void ContactListener::BeginContact(b2Contact *contact) {
    b2Fixture *a = contact->GetFixtureA();
    b2Fixture *b = contact->GetFixtureB();
    if (a->GetFilterData().maskBits == 1) {
        auto usserData = static_cast<UserData *>(a->GetBody()->GetUserData());
        if (usserData != nullptr) {
            usserData->IsGround = true;
            return;
        }
    }
    if (b->GetFilterData().maskBits == 1) {
        auto usserData = static_cast<UserData *>(b->GetBody()->GetUserData());
        if (usserData != nullptr) {
            usserData->IsGround = true;
        }
    }
}
void ContactListener::EndContact(b2Contact *contact) {
    b2ContactListener::EndContact(contact);
}


#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        ///  _log-> Error("SDL could not initialize! SDL Error: "+ std::string(SDL_GetError()));
        return false;
    }

    SDL_Window *gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


    SDL_Renderer *renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {

        cout << std::string(SDL_GetError());
    }

    b2Vec2 gravity(0.0f, 10.0f);
    Render::Init(renderer, std::make_shared<Camera>());
    Graphic::PhysicDraw physicDraw(StP);
    b2World world(gravity);
    world.SetDebugDraw(&physicDraw);
    ContactListener contactListener;
    world.SetContactListener(&contactListener);
    float hx = 800.0f; //ширина
    float hy = 10.0f;

    float corx = 0.0f + hx / 2.0f;
    float cory = 500.0f + hy / 2.0f;


    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(toPhysic(corx), toPhysic(cory));
    b2Body *groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(toPhysic(hx / 2), toPhysic(hy / 2));
    groundBody->CreateFixture(&groundBox, 0.0f);


    float phx = 10.0f; //ширина
    float phy = 150.0f;

    float pcorx = 100.0f + phx / 2.0f;
    float pcory = 0.0f + phy / 2.0f;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(toPhysic(pcorx), toPhysic(pcory));
    b2Body *body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(toPhysic(phx / 2), toPhysic(phy / 2));
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    auto posBody = body->GetPosition();
    b2BodyDef bodyDefSensor;
    bodyDefSensor.type = b2_dynamicBody;

    bodyDefSensor.position.Set(posBody.x, posBody.y + toPhysic(phy / 2));
    b2Body *bodySensor = world.CreateBody(&bodyDefSensor);
    b2PolygonShape dynamicBoxSensor;
    dynamicBoxSensor.SetAsBox(toPhysic(phx / 2), toPhysic(phy / 2 / 100));
//
    UserData userData;
    userData.IsGround = false;
    bodySensor->SetUserData(&userData);
    b2FixtureDef fixtureSensorGroudDef;
    fixtureSensorGroudDef.filter.maskBits = 1;
    fixtureSensorGroudDef.density = 1.0f;
    fixtureSensorGroudDef.friction = 0.3f;
    fixtureSensorGroudDef.isSensor = true;
    fixtureSensorGroudDef.shape = &dynamicBoxSensor;
    bodySensor->CreateFixture(&fixtureSensorGroudDef);

    b2WeldJointDef b2JointDef1;

    b2JointDef1.Initialize(body, bodySensor, body->GetPosition());

    auto join = world.CreateJoint(&b2JointDef1);

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 3;
    int32 positionIterations = 2;


    std::vector<SDL_Point> points;
    SDL_Point point;
    point.x = 200;
    point.y = 200;
    points.push_back(point);
    point.x = 300;
    point.y = 200;
    points.push_back(point);
    point.x = 300;
    point.y = 300;
    points.push_back(point);
    point.x = 200;
    point.y = 300;
    points.push_back(point);
    points.push_back(points.front());


    bool _run = true;
    while (_run) {

        SDL_Event event;
        if (SDL_PollEvent(&event) != 0) {

            switch (event.type) {
                case SDL_QUIT : {
                    _run = false;
                    break;
                }
                case SDL_KEYDOWN : {

                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT: {
                            //  ->ToLeft(delta);
                            break;
                        }
                        case SDLK_RIGHT: {
                            //  this->ToRight(delta);
                            break;
                        }
                        case SDLK_UP: {
                            if(userData.IsGround== true) {
                                body->SetLinearVelocity(b2Vec2(0, -2));
                                userData.IsGround = false;
                            }
                            break;
                        }
                    }
                }

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
        SDL_RenderDrawLine(renderer, 10, 10, 10, 400);
        SDL_RenderDrawLine(renderer, 10, 10, 400, 10);

        //  SDL_RenderDrawLines(renderer, points.data(), points.size());

        world.Step(timeStep, velocityIterations, positionIterations);
        world.DrawDebugData();

        SDL_RenderPresent(renderer);
        b2Vec2 position = body->GetPosition();
        float32 angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x * StP, position.y * StP, angle);
        std::cout<<"IsGroud : "<<userData.IsGround<<std::endl;

        fflush(stdout);
        SDL_Delay(50);
    }
}
