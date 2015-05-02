//
// Created by ִלטענטי on 27.04.2015.
//

#include "scriptBinding/BoundScript.hpp"

BoundScript::BoundScript(shared_ptr<Script> script) : _script(script) { };

BoundScript::~BoundScript() { };

int BoundScript::GetHeight() {
    LuaRef s = getGlobal(_script->GetLuaState(), "Height");
    return s.cast<int>();
}

int BoundScript::GetWidth() {
    LuaRef s = getGlobal(_script->GetLuaState(), "Width");
    return s.cast<int>();
}