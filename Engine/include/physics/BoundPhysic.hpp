#ifndef BOUNDPHYSIC_HPP_INCLUDED
#define BOUNDPHYSIC_HPP_INCLUDED


#include "BasePhysicBody.hpp"
#include "Utils/Point.hpp"

using namespace Utils;
namespace Physic {
    class BoundPhysic : public BasePhysicBody {

    public:
        BoundPhysic(std::shared_ptr<b2World> world, int width, int height, FPoint position);
    };
}

#endif