#include "physics/BasePhysicBody.hpp"

namespace Physic {
    BasePhysicBody::BasePhysicBody(float physicCoffSize) {
        _physicCoffSize = physicCoffSize;
    }

    BasePhysicBody::~BasePhysicBody() {
    }

    FPoint BasePhysicBody::GetPosition() {
        b2Vec2 position = _body-> GetPosition();
        return FPoint(toScreanSize(position.x), toScreanSize(position.y));
    }

    void BasePhysicBody::SetUserData(void *data) {
        _body->SetUserData(data);
    }

    float BasePhysicBody::toScreanSize(float i) {
        return i * _physicCoffSize;
    }

    float BasePhysicBody::toPhysicSize(float i) {
        return i / _physicCoffSize;
    }
}