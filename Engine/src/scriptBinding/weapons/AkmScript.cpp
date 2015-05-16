#include "scriptBinding/weapons/AkmScript.hpp"

AkmScript::AkmScript(shared_ptr<Script> script)
        : BaseScriptBinding(script, "PlayerScript") { }

string AkmScript::getTextureName() const {
    return GetGlobalVar<string>((string) "texture");
}

IPoint AkmScript::getPosition() const {
    return IPoint(GetGlobalVar<int>((string) "positionx"), GetGlobalVar<int>((string) "positiony"));
}
