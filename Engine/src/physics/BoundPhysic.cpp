#include "physics/BoundPhysic.hpp"

namespace Physic {
    BoundPhysic::BoundPhysic(std::shared_ptr<b2World> world, int height, int width, IPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        _body = world->CreateBody(&bodyDef);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        _body->CreateFixture(&fixtureDef);
        _body->SetTransform(b2Vec2(position.x, position.y), 0);
    }

}