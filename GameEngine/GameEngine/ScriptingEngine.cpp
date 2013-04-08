#include "ScriptingEngine.h"

boost::scoped_ptr<ScriptingEngine> ScriptingEngine::pScriptingEngine(NULL);

ScriptingEngine::ScriptingEngine()
{
	lState = lua_open();
	luaL_openlibs(lState);

	luabind::open(lState);
	
	ExposeFunctions();
}


ScriptingEngine::~ScriptingEngine(void)
{
	lua_close(lState);
}

void ScriptingEngine::SetScript(std::string gamefile)
{
	if(int error = luaL_dofile(lState, gamefile.c_str()) != 0)
	{
		throw std::runtime_error("ERROR: Problem opening Lua file " + gamefile);
	}
}

boost::scoped_ptr<ScriptingEngine>* ScriptingEngine::GetInstance()
{
	if(pScriptingEngine.get() == NULL)
	{
		pScriptingEngine.reset(new ScriptingEngine);
	}

	return &pScriptingEngine;
}

void ScriptingEngine::ExposeFunctions()
{
	/*luabind::module(lState)
	[
		//.def("SetKey", &((*Input::GetInstance())->GetKeyboard()->DefineKey))
	];*/
}