//
// Created by akum on 05.04.2015.
//

#ifndef GAME_PLAYERSCRIPT_HPP
#define GAME_PLAYERSCRIPT_HPP

#include <memory>
#include "Script.hpp"

using std::shared_ptr;

class PlayerScript {

public:
    PlayerScript(shared_ptr<Script> script);

    int GetJuamSize();

    int GetStepSIze();

private:
    shared_ptr<Script> _script;
};

#endif //GAME_PLAYERSCRIPT_HPP
