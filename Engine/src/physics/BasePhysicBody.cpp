#include "physics/BasePhysicBody.hpp"

namespace Physic {
    BasePhysicBody::BasePhysicBody() {
    }

    BasePhysicBody::~BasePhysicBody() {
    }

    IPoint BasePhysicBody::GetPosition() {
        b2Vec2 localPoint = _body->GetPosition();
        return IPoint(localPoint.x, localPoint.y);
    }

    void BasePhysicBody::SetUserData(void *data) {
        _body->SetUserData(data);
    }
}