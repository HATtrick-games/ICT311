/**
 * \file	StateMachine.h
 *
 * \brief	Declares the state machine class.
**/

#pragma once

#include <iostream>

#include "State.h"

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
		previousState = NULL;
		currentState = NULL;
		globalState = NULL;
	};

	/**
	 * \fn	virtual StateMachine::~StateMachine(void);
	 *
	 * \brief	Destructor.
	**/

	virtual ~StateMachine(void);

	/**
	 * \fn	void StateMachine::SetPreviousState(State<T>* st)
	 *
	 * \brief	Sets previous state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetPreviousState(State<T>* st) { previousState = st; }

	/**
	 * \fn	void StateMachine::SetCurrentState(State<T>* st)
	 *
	 * \brief	Sets current state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetCurrentState(State<T>* st) { currentState = st; }

	/**
	 * \fn	void StateMachine::SetGlobalState(State<T>* st)
	 *
	 * \brief	Sets global state.
	 *
	 * \param [in,out]	st	If non-null, the st.
	**/

	void SetGlobalState(State<T>* st) { globalState = st; }

	/**
	 * \fn	void StateMachine::Update() const;
	 *
	 * \brief	Updates this object.
	**/

	void Update() const;

	/**
	 * \fn	void StateMachine::ChangeState(State<T>* newState);
	 *
	 * \brief	Change state.
	 *
	 * \param [in,out]	newState	If non-null, state of the new.
	**/

	void ChangeState(State<T>* newState);

	/**
	 * \fn	void StateMachine::RevertToPreviousState();
	 *
	 * \brief	Revert to previous state.
	**/

	void RevertToPreviousState();

	/**
	 * \fn	State<T>* StateMachine::GetPreviousState()
	 *
	 * \brief	Gets the previous state.
	 *
	 * \return	null if it fails, else the previous state.
	**/

	State<T>* GetPreviousState() { return previousState; }

	/**
	 * \fn	State<T>* StateMachine::GetCurrentState()
	 *
	 * \brief	Gets current state.
	 *
	 * \return	null if it fails, else the current state.
	**/

	State<T>* GetCurrentState() { return currentState; }

	/**
	 * \fn	State<T>* StateMachine::GetGlobalState()
	 *
	 * \brief	Gets global state.
	 *
	 * \return	null if it fails, else the global state.
	**/

	State<T>* GetGlobalState() { return globalState; }

	/**
	 * \fn	bool StateMachine::IsInState(const State<T>& st) const;
	 *
	 * \brief	Query if 'st' is in state.
	 *
	 * \param	st	The st.
	 *
	 * \return	true if in state, false if not.
	**/

	bool IsInState(const State<T>& st) const;
private:
	T* object; //!< The object
	State<T>* previousState; //!< The previous state
	State<T>* currentState; //!< The current state
	State<T> *globalState;  //!< The global state
};

template <class T>
void StateMachine::Update()
{
	// global state has been set
	if(globaState)
		globalState->Execute(object);

	// current state has been set
	if(currentState)
		currentState->Execture(object);
}

template <class T>
void StateMachine::ChangeState(State<T>* newState)
{
	if(currentState)
	{
		// save the current state as previous state
		previousState = currentState;
		// call the exit function of the current state 
		currentState->Exit(object);
	}

	// change current state to new state
	currentState = newState;
	// call the enter function of the new state
	currentState->Enter(object);
}

template <class T>
void StateMachine::RevertToPreviousState()
{
	currentState = previousState;
}

template <class T>
bool StateMachine::IsInState(const State<T>& st)
{
	return typeid(*currentState) == typeid(st);
}