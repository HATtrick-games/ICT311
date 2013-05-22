#pragma once

#include "stdafx.h"
#include "Vector2D.h"
#include "AIObject.h"
#include "Telegram.h"
#include "State.h"
#include "StateMachine.h"

/**
 * \class	AIScripting
 *
 * \brief	AI scripting.
**/
class AIScripting
{
public:

	/**
	 * \fn	AIScripting::AIScripting(void);
	 *
	 * \brief	Default constructor.
	**/

	AIScripting(void);

	/**
	 * \fn	AIScripting::~AIScripting(void);
	 *
	 * \brief	Destructor.
	**/

	~AIScripting(void);

	lua_State* lState;  //!< The Lua state

	/**
	 * \fn	bool AIScripting::LoadScript(std::string filename);
	 *
	 * \brief	Loads a script.
	 *
	 * \param	filename	Filename of the file.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool LoadScript(std::string filename);

	/**
	 * \fn	static boost::scoped_ptr<AIScripting>* AIScripting::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \return	null if it fails, else the instance.
	**/
	static boost::scoped_ptr<AIScripting>* GetInstance();
private:
	static boost::scoped_ptr<AIScripting> singleton;	//!< The singleton

	void LoadLuaLibraries();
	void RegisterClasses();

	void RegisterStateMachine(lua_State* state);
	void RegisterGameObject(lua_State* state);
	void RegisterVector2D(lua_State* state);
	void RegisterMessage(lua_State* state);
	void RegisterTelegram(lua_State* state);
};

