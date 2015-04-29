#ifndef GAME_PLAYERSCRIPT_HPP
#define GAME_PLAYERSCRIPT_HPP

#include <memory>
#include "BaseScriptBinding.hpp"

using std::shared_ptr;

class PlayerScript : public BaseScriptBinding {

public:
    PlayerScript(shared_ptr<Script> script);

    int GetJuamSize() const;

    int GetStepSIze() const;

    int GetWidth() const;

    int GetHeight() const;

    string GetSpriteAnimationName() const;
};

#endif //GAME_PLAYERSCRIPT_HPP
