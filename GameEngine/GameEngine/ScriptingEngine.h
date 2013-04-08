#pragma once

#include "Input.h"

#include <boost/scoped_ptr.hpp>

#include <lua.hpp>
#include <luabind/luabind.hpp>

class ScriptingEngine
{
public:
	ScriptingEngine(void);
	~ScriptingEngine(void);

	void SetScript(std::string gamefile);

	static boost::scoped_ptr<ScriptingEngine>* GetInstance();
private:
	static boost::scoped_ptr<ScriptingEngine> pScriptingEngine;

	void ExposeFunctions();

	lua_State* lState;
};

