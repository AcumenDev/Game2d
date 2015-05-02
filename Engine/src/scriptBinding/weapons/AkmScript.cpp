#include "scriptBinding/weapons/AkmScript.hpp"

AkmScript::AkmScript(shared_ptr<Script> script) : BaseScriptBinding(script, "AkmScript") {
}

string AkmScript::getTextureName() {
    return GetGlobalVar<string>("texture");
}
