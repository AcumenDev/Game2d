#ifndef GAME_WEAPONSMANAGER_HPP
#define GAME_WEAPONSMANAGER_HPP

#include <memory>
#include "gameObjects/Player.hpp"
#include "gameObjects/weapons/WeaponBase.hpp"

using std::shared_ptr;

class WeaponsManager {
public:
    WeaponsManager() {
        _className = "WeaponsManager";
    }

    void SetPlayer(shared_ptr<Player> player) {
        _player = player;
    }

    void SetWeapon(shared_ptr<WeaponBase> weapon) {
        if (_player) {
            _player->SetWeapon(weapon);
        } else {
            Logger::Get()->Error(_className, "Player not initialized");
        }
    }

private:
    shared_ptr<Player> _player;
    string _className;
};

#endif //GAME_WEAPONSMANAGER_HPP
