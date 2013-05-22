#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "Telegram.h"
#include "AIMovement.h"
#include "MessageDispatcher.h"

/**
 * \class	AIObject
 *
 * \brief	Used to define all Artificially Intelligent objects.
**/
class AIObject : public GameObject
{
public:

	/**
	 * \fn	AIObject::AIObject(void);
	 *
	 * \brief	Default constructor.
	**/
	AIObject(void);

	/**
	 * \fn	AIObject::AIObject(Vector2D pos, Vector2D vel, int id);
	 *
	 * \brief	Constructor.
	 *
	 * \param	pos	The initial position of the game object. 
	 * \param	vel	The initial velocity of the game object.
	 * \param	id 	The identifier.
	**/
	AIObject(Vector2D pos, Vector2D vel, int id);

	/**
	 * \fn	AIObject::~AIObject(void);
	 *
	 * \brief	Destructor.
	**/
	~AIObject(void);

	/**
	 * \fn	void AIObject::UpdateAI(float timeElapsed);
	 *
	 * \brief	Updates AI using the given elapsed time.
	 *
	 * \param	timeElapsed	The time elapsed.
	**/
	void UpdateAI(float timeElapsed);

	/**
	 * \fn	int AIObject::GetID()
	 *
	 * \brief	Gets the identifier.
	 *
	 * \return	The identifier.
	**/
	int GetID() { return ID; }

	/**
	 * \fn	void AIObject::SetID(int id)
	 *
	 * \brief	Sets the identifier.
	 *
	 * \param	id	The identifier.
	**/
	void SetID(int id) { ID = id; }

	/**
	 * \fn	bool AIObject::HandleMessage(const Telegram& msg)
	 *
	 * \brief	Handles the message described by msg.
	 *
	 * \param	msg	The message.
	 *
	 * \return	true if it succeeds, false if it fails.
	**/
	bool HandleMessage(const Telegram& msg) { return aiFSM->HandleMessage(msg); }

	/**
	 * \fn	void AIObject::SendMessage(double delay, int sender, int receiver,
	 * 		int msg, luabind::object extraInfo);
	 *
	 * \brief	Sends a message.
	 *
	 * \param	delay	 	The delay.
	 * \param	sender   	The sender.
	 * \param	receiver 	The receiver.
	 * \param	msg		 	The message.
	 * \param	extraInfo	Any additional information.
	**/
	void SendMessage(double delay, int sender, int receiver, int msg, luabind::object extraInfo);

	/**
	 * \fn	StateMachine<AIObject>* AIObject::GetFSM() const
	 *
	 * \brief	Gets the state machine used to describe this AI objects
	 * 			behaviors.
	 *
	 * \return	null if it fails, else the state machine.
	**/
	StateMachine<AIObject>* GetFSM() const { return aiFSM; }

	/**
	 * \fn	void AIObject::SetCurrentState(const luabind::object &st)
	 *
	 * \brief	Sets current state of the State Machine.
	 *
	 * \param	st	The current state to set to.
	**/
	void SetCurrentState(const luabind::object &st) { aiFSM->SetCurrentState(st); }

	/**
	 * \fn	void AIObject::SetTarget(GameObject* t)
	 *
	 * \brief	Sets a target object that the AI object is targeting.
	 *
	 * \param [in,out]	t	If non-null, the GameObject* to process.
	**/

	void SetTarget(GameObject* t) { target = t; }

	/**
	 * \fn	float AIObject::DistanceFromTarget() const
	 *
	 * \brief	Gets the distance from target.
	 *
	 * \return	The distance from the target object
	**/
	float DistanceFromTarget() const { if(target != NULL) { return (target->GetPosition() - Position).length();}else{return -1.0f;} }

	/**
	 * \fn	void AIObject::PursueTarget();
	 *
	 * \brief	Pursues the target.
	**/

	void PursueTarget();

	/**
	 * \fn	void AIObject::FleeTarget();
	 *
	 * \brief	Flees the target.
	**/

	void FleeTarget();

	/**
	 * \fn	void AIObject::EvadeTarget();
	 *
	 * \brief	Evades the target.
	**/

	void EvadeTarget();

	/**
	 * \fn	void AIObject::Wander();
	 *
	 * \brief	Wanders around randomly.
	**/

	void Wander();

	/**
	 * \fn	bool AIObject::CanViewTarget();
	 *
	 * \brief	Determine if we can view target.
	 *
	 * \return	true if we can view target, false if not.
	**/
	bool CanViewTarget();
private:
	StateMachine<AIObject>* aiFSM;  //!< The ai state machine

	AIMovement movementFunctions;   //!< The movement functions
	GameObject* target; //!< Target for the

	float aiTimeElapsed;	//!< The ai time elapsed

	int ID; //!< The identifier
};

