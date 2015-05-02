#include "scriptBinding/BoundScript.hpp"

BoundScript::BoundScript(shared_ptr<Script> script) : BaseScriptBinding(script, "BoundScript") { };

BoundScript::~BoundScript() { };

int BoundScript::GetHeight() {
    return GetGlobalVar<int>((string) "height");
}

int BoundScript::GetWidth() {
    return GetGlobalVar<int>((string) "width");
}