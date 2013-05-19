#pragma once

/**
 * \class	State
 *
 * \brief	Defines a generic state to be used with a state machine.
 *
 * \tparam	T	Generic type parameter.
**/
template <class T>
class State
{
public:

	/**
	 * \fn	virtual State::~State()
	 *
	 * \brief	Virtual Destructor.
	**/
	virtual ~State() { };

	/**
	 * \fn	virtual void State::Load(T*) = 0;
	 *
	 * \brief	Loads the given state
	 *
	 * \param [in,out]	parameter1	The object to load.
	**/
	virtual void Load(T*) = 0;

	/**
	 * \fn	virtual void State::Update(T*) = 0;
	 *
	 * \brief	Updates the given state.
	 *
	 * \param [in,out]	parameter1	The object to update.
	**/
	virtual void Update(T*) = 0;

	/**
	 * \fn	virtual void State::Unload(T*) = 0;
	 *
	 * \brief	Unloads the given state.
	 *
	 * \param [in,out]	parameter1	The object to unload.
	**/
	virtual void Unload(T*) = 0;
};

