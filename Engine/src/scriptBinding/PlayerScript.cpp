//
// Created by akum on 05.04.2015.
//

#include "scriptBinding/PlayerScript.hpp"

PlayerScript::PlayerScript(shared_ptr<Script> script)
        : _script(script) { }


int PlayerScript::GetJuamSize() {
    LuaRef s = getGlobal(_script->GetLuaState(), "jumpSize");
    return s.cast<int>();
}

int PlayerScript::GetStepSIze() {
    LuaRef s = getGlobal(_script->GetLuaState(), "stepSize");
    return s.cast<int>();
}
