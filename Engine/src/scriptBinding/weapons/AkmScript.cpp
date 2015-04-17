#include "scriptBinding/weapons/AkmScript.hpp"

AkmScript::AkmScript(shared_ptr<Script> script) {
    _script = script;
}

string AkmScript::getTextureName() {
    LuaRef s = getGlobal(_script->GetLuaState(), "texture");
    return s.cast<string>();
}
