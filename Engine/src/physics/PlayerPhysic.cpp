#include "physics/PlayerPhysic.hpp"

namespace Physic {
    PlayerPhysic::PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, IPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(position.x, position.y);
      //  bodyDef.active= true;
        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        _body = world->CreateBody(&bodyDef);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
       // fixtureDef.density = 1.0f;
      //  fixtureDef.friction = 0.3f;
        _body->CreateFixture(&fixtureDef);


    }

    PlayerPhysic::~PlayerPhysic() {

    }
}