#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "Telegram.h"
#include "AIMovement.h"
#include "MessageDispatcher.h"

class AIObject : public GameObject
{
public:
	AIObject(void);
	AIObject(Vector2D pos, Vector2D vel, int id);

	~AIObject(void);

	void UpdateAI(float timeElapsed);

	int GetID() { return ID; }
	void SetID(int id) { ID = id; }
	
	bool HandleMessage(const Telegram& msg) { return aiFSM->HandleMessage(msg); }
	void SendMessage(double delay, int sender, int receiver, int msg, luabind::object extraInfo);

	StateMachine<AIObject>* GetFSM() const { return aiFSM; }
	void SetCurrentState(const luabind::object &st) { aiFSM->SetCurrentState(st); }

	void SetTarget(GameObject* t) { target = t; }
	float DistanceFromTarget() const { return (target->GetPosition() - Position).length(); }
	void PursueTarget();
	void FleeTarget();
	void EvadeTarget();
	void Wander();
	bool CanViewTarget();
private:
	StateMachine<AIObject>* aiFSM;

	AIMovement movementFunctions;
	GameObject* target;

	float aiTimeElapsed;

	int ID;
};

