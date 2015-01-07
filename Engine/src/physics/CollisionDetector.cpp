#include "physics/CollisionDetector.hpp"

namespace Physic {
    CollisionDetector::CollisionDetector() {
    }

    CollisionDetector::~CollisionDetector() {

    }

    void CollisionDetector::BeginContact(b2Contact *contact) {
        b2Fixture *a = contact->GetFixtureA();
        b2Fixture *b = contact->GetFixtureB();
        if (a->GetFilterData().maskBits == 1) {
            auto usserData = static_cast<Player *>(a->GetBody()->GetUserData());
            if (usserData != nullptr) {
                usserData->SetIsOnGround(true);
                return;
            }
        }
        if (b->GetFilterData().maskBits == 1) {
            auto usserData = static_cast<Player *>(b->GetBody()->GetUserData());
            if (usserData != nullptr) {
                usserData->SetIsOnGround(true);
            }
        }
    }
}