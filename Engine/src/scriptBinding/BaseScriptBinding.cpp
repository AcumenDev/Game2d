#include "scriptBinding/BaseScriptBinding.hpp"

BaseScriptBinding::BaseScriptBinding(shared_ptr<Script> script, string className) {
    _script = script;
    _className = className;
}
