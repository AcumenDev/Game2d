#include "physics/BoundPhysic.hpp"

namespace Physic {
    BoundPhysic::BoundPhysic(std::shared_ptr<b2World> world, int height, int width, IPoint position) {
        b2BodyDef bodyDef;
      //  bodyDef.type = b2_staticBody;
       // bodyDef.active= true;
        bodyDef.position.Set(position.x, position.y);
        _body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
       /// fixtureDef.restitution= 10;

        _body->CreateFixture(&fixtureDef);
    }
}