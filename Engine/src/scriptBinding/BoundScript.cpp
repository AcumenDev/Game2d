#include "scriptBinding/BoundScript.hpp"

BoundScript::BoundScript(shared_ptr<Script> script) : BaseScriptBinding(script, "BoundScript") { };

BoundScript::~BoundScript() { };

int BoundScript::getHeight() {
    return GetGlobalVar<int>((string) "height");
}

int BoundScript::getWidth() {
    return GetGlobalVar<int>((string) "width");
}

string BoundScript::getTextureName() {
    return GetGlobalVar<string>("texture");
}