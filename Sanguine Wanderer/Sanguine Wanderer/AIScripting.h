#pragma once

#include "stdafx.h"
#include "Vector2D.h"
#include "AIObject.h"
#include "Telegram.h"
#include "State.h"
#include "StateMachine.h"

class AIScripting
{
public:
	AIScripting(void);
	~AIScripting(void);

	lua_State* lState;

	bool LoadScript(std::string filename);

	static boost::scoped_ptr<AIScripting>* GetInstance();
private:
	static boost::scoped_ptr<AIScripting> singleton;

	void LoadLuaLibraries();
	void RegisterClasses();

	void RegisterStateMachine(lua_State* state);
	void RegisterGameObject(lua_State* state);
	void RegisterVector2D(lua_State* state);
	void RegisterMessage(lua_State* state);
	void RegisterTelegram(lua_State* state);
};

