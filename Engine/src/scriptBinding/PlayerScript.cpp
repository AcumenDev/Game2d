#include "scriptBinding/PlayerScript.hpp"

PlayerScript::PlayerScript(shared_ptr<Script> script)
        : BaseScriptBinding(script, "PlayerScript") { }

int PlayerScript::GetJuamSize() const {
    return GetGlobalVar<int>((string) "jumpSize");
}

int PlayerScript::GetStepSIze() const {
    return GetGlobalVar<int>((string) "stepSize");
}

int PlayerScript::GetWidth() const {
    return GetGlobalVar<int>((string) "width");
}

int PlayerScript::GetHeight() const {
    return GetGlobalVar<int>((string) "height");
}

string PlayerScript::GetSpriteAnimationName() const {
    return GetGlobalVar<string>((string) "spriteAnimationName");
}
