#include "physics/BoundPhysic.hpp"

namespace Physic {
    BoundPhysic::BoundPhysic(std::shared_ptr<b2World> world, int height, int width, FPoint position) {
        b2BodyDef bodyDef;
      // bodyDef.type = b2_dynamicBody;
       // bodyDef.active= true;
        auto physicPosition = position.ToPhysicWorld();
        bodyDef.position.Set(physicPosition.x, physicPosition.y);

        _body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
      //  fixtureDef.density = 1.0;
      //  fixtureDef.friction = 0.3;
      //  fixtureDef.restitution = 0.1;
       /// fixtureDef.restitution= 10;

        _body->CreateFixture(&fixtureDef);
    }
}