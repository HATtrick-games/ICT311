/**
 * \file	StateMachine.h
 *
 * \brief	Declares the state machine class.
**/

#pragma once

#include <iostream>
#include <lua.hpp>
#include <luabind/luabind.hpp>

#include "State.h"
#include "Telegram.h"

/**
 * \class	StateMachine
 *
 * \brief	State machine.
 *
 * \tparam	T	Generic type parameter.
**/

template <class T>
class StateMachine
{
public:

	/**
	 * \fn	StateMachine::StateMachine(T* fsmObject)
	 *
	 * \brief	Constructor.
	 *
	 * \param [in,out]	fsmObject	If non-null, the fsm object.
	**/

	StateMachine(T* fsmObject)
	{
		object = fsmObject;
	};

	/**
	 * \fn	StateMachine::StateMachine()
	 *
	 * \brief	Default constructor.
	**/
	StateMachine()
	{
		object = NULL;
	}

	/**
	 * \fn	void StateMachine::SetPreviousState(State<T>* st)
	 *
	 * \brief	Sets previous state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetPreviousState(const luabind::object& st) { previousState = st; }

	/**
	 * \fn	void StateMachine::SetCurrentState(State<T>* st)
	 *
	 * \brief	Sets current state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetCurrentState(const luabind::object& st) { currentState = st; }

	/**
	 * \fn	void StateMachine::SetGlobalState(State<T>* st)
	 *
	 * \brief	Sets global state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetGlobalState(const luabind::object st) { globalState = st; globalState["enter"](object); }

	/**
	 * \fn	void StateMachine::Update() const;
	 *
	 * \brief	Updates this object.
	**/

	void Update()
	{
		// global state has been set
		if(globalState.is_valid())
			globalState["execute"](object);

		// current state has been set
		if(currentState.is_valid())
			currentState["execute"](object);
	}

	/**
	 * \fn	void StateMachine::ChangeState(State<T>* newState);
	 *
	 * \brief	Change state.
	 *
	 * \param [in,out]	newState	If non-null, state of the new.
	**/

	void ChangeState(const luabind::object& newState)
	{
		if(currentState.is_valid())
		{
			// save the current state as previous state
			previousState = currentState;
			// call the exit function of the current state 
			currentState["exit"](object);
		}

		// change current state to new state
		currentState = newState;
		// call the enter function of the new state
		currentState["enter"](object);
	}

	/**
	 * \fn	void StateMachine::RevertToPreviousState();
	 *
	 * \brief	Revert to previous state.
	**/

	void RevertToPreviousState()
	{
		currentState = previousState;
	}

	/**
	 * \fn	State<T>* StateMachine::GetPreviousState()
	 *
	 * \brief	Gets the previous state.
	 *
	 * \return	null if it fails, else the previous state.
	**/

	luabind::object& GetPreviousState() { return previousState; }

	/**
	 * \fn	State<T>* StateMachine::GetCurrentState()
	 *
	 * \brief	Gets current state.
	 *
	 * \return	null if it fails, else the current state.
	**/

	luabind::object& GetCurrentState() { return currentState; }

	/**
	 * \fn	State<T>* StateMachine::GetGlobalState()
	 *
	 * \brief	Gets global state.
	 *
	 * \return	null if it fails, else the global state.
	**/

	luabind::object& GetGlobalState() { return globalState; }

	/**
	 * \fn	bool StateMachine::HandleMessage(const Telegram& msg)
	 *
	 * \brief	Handles the message described by msg.
	 *
	 * \param	msg	The message.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/

	bool HandleMessage(const Telegram& msg)
	{
		if(currentState.is_valid())
		{
			currentState["onMessage"](object, msg);
			return true;
		}

		if(globalState.is_valid())
		{
			globalState["onMessage"](object, msg);
			return true;
		}

		return false;
	}

	/**
	 * \fn	virtual StateMachine::~StateMachine()
	 *
	 * \brief	Destructor.
	**/

	virtual ~StateMachine() {};
private:
	T* object; //!< The object
	luabind::object previousState; //!< The previous state
	luabind::object currentState; //!< The current state
	luabind::object globalState;  //!< The global state
};