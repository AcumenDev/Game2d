#ifndef GAME_WEAPONBASE_HPP
#define GAME_WEAPONBASE_HPP

#include "gameObjects/GameObjectBase.hpp"
#include "Utils/Point.hpp"
using namespace Utils;
class WeaponBase : public virtual GameObjectBase {

public:
    virtual void Shot() = 0;

    virtual void SetPosition(FPoint point) = 0;
};

#endif //GAME_WEAPONBASE_HPP
