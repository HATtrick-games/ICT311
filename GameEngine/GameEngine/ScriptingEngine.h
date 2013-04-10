#pragma once

#include "Game.h"
#include "Input.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "AiObject.h"
#include "Camera.h"

#include <boost/scoped_ptr.hpp>

#include <lua.hpp>
#include <luabind/luabind.hpp>

#include <iostream>

/**
 * \class	ScriptingEngine
 *
 * \brief	Provides an interface between C++ and Lua script
 * 			to create a game.
 * \author	Timothy Veletta
 */

class ScriptingEngine
{
public:

	/**
	 * \fn	ScriptingEngine::ScriptingEngine(void);
	 *
	 * \brief	Default constructor.
	 */

	ScriptingEngine(void);
	~ScriptingEngine(void);

	/**
	 * \fn	void ScriptingEngine::SetScript(std::string gamefile);
	 *
	 * \brief	Sets the script to run the game from.
	 *
	 * \param	gamefile	The gamefile.
	 */
	void SetScript(std::string gamefile);

	/**
	 * \fn	void ScriptingEngine::LoadResources();
	 *
	 * \brief	Calls the LoadResources function in the Lua script.
	 */
	void LoadResources();

	/**
	 * \fn	void ScriptingEngine::Initialise();
	 *
	 * \brief	Calls the Initialise function in the Lua script.
	 */
	void Initialise();

	/**
	 * \fn	void ScriptingEngine::Update(float time);
	 *
	 * \brief	Calls the Update function in the Lua script.
	 *
	 * \param	time	The time.
	 */
	void Update(float time);

	/**
	 * \fn	static boost::scoped_ptr<ScriptingEngine>* ScriptingEngine::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<ScriptingEngine>* GetInstance();
private:
	static boost::scoped_ptr<ScriptingEngine> pScriptingEngine; //!< The scripting engine

	void ExposeFunctions();

	// Input functions
	static void DefineKey(std::string id, int k);
	static void DefineMouse(std::string id, int k);
	static bool GetKey(std::string id);
	static bool GetMouse(std::string id);
	static int GetMouseX();
	static int GetMouseY();

	// Asset functions
	static bool AddAsset(std::string file, std::string type);

	static void AddAIObject(std::string id, std::string asset, float x, float y, float z);
	static void PlayerVelocity(float x, float z);
	static void CameraRotation(float deg);

	lua_State* lState;  //!< The Lua state
};

