#include "physics/PlayerPhysic.hpp"

namespace Physic {
    PlayerPhysic::PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, FPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type =  b2_dynamicBody;
        auto physicPosition = position.ToPhysicWorld();
        bodyDef.position.Set(physicPosition.x, physicPosition.y);
      //  bodyDef.active= true;
        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        _body = world->CreateBody(&bodyDef);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
      //  fixtureDef.density = 1.0f;
      //  fixtureDef.friction = 0.001f;

        _body->CreateFixture(&fixtureDef);

          //      b2MassData b2MassData1;
     //   b2MassData1.mass=10;
      //  _body->SetMassData(&b2MassData1);
    }

    PlayerPhysic::~PlayerPhysic() {

    }
}