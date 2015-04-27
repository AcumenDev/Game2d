//
// Created by ִלטענטי on 27.04.2015.
//

#include "scriptBinding/BoundScript.hpp"

BoundScript::BoundScript(shared_ptr<Script> script) : _script(script) { };

int BoundScript::GetHeight() {
    LuaRef s = getGlobal(_script->GetLuaState(), "Height");
    return s.cast<int>();
}

int BoundScript::GetWeight() {
    LuaRef s = getGlobal(_script->GetLuaState(), "Weight");
    return s.cast<int>();
}