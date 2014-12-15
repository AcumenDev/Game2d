#include "physics/PlayerPhysic.hpp"

namespace Physic {
    PlayerPhysic::PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, IPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;

        b2PolygonShape shape;
        shape.SetAsBox(width, height);
        _body = world->CreateBody(&bodyDef);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        // fixtureDef.density = 10;
        // fixtureDef.friction = 1;
        // fixtureDef.restitution = 0f;
        _body->CreateFixture(&fixtureDef);

        _body->SetTransform(b2Vec2(position.x, position.y), 0);

    }
    PlayerPhysic::~PlayerPhysic() {

    }
}