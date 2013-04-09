#pragma once

#include "Game.h"
#include "Input.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "AiObject.h"

#include <boost/scoped_ptr.hpp>

#include <lua.hpp>
#include <luabind/luabind.hpp>

#include <iostream>

class ScriptingEngine
{
public:
	ScriptingEngine(void);
	~ScriptingEngine(void);

	void SetScript(std::string gamefile);

	void LoadResources();

	void Initialise();

	void Update(float time);

	static boost::scoped_ptr<ScriptingEngine>* GetInstance();
private:
	static boost::scoped_ptr<ScriptingEngine> pScriptingEngine;

	void ExposeFunctions();

	// Input functions
	static void DefineKey(std::string id, int k);
	static void DefineMouse(std::string id, int k);
	static bool GetKey(std::string id);
	static bool GetMouse(std::string id);

	// Asset functions
	static bool AddAsset(std::string file, std::string type);
	static void AddGameObject(std::string id, GameObject obj);

	lua_State* lState;
};

