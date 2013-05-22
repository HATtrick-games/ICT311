#include "StdAfx.h"
#include "AIObject.h"


AIObject::AIObject(void)
{
	aiFSM = new StateMachine<AIObject>(this);
	Position = glm::vec3();
	Velocity = glm::vec3();
	aiTimeElapsed = 0;
	ID = 0;
	target = NULL;
}

AIObject::AIObject(Vector2D pos, Vector2D vel, int id)
{
	Position = pos.ToGLM();
	Velocity = vel.ToGLM();
	ID = id;
	aiFSM = new StateMachine<AIObject>(this);
	aiTimeElapsed = 0.0f;
	target = NULL;
}

AIObject::~AIObject()
{
	delete aiFSM;
}

void AIObject::UpdateAI(float timeElapsed)
{
	aiTimeElapsed = timeElapsed;

	Position += (Velocity * aiTimeElapsed);

	aiFSM->Update();
}

void AIObject::SendMessage(double delay, int sender, int receiver, int msg, luabind::object extraInfo)
{
	(*MessageDispatcher::GetInstance())->DispatchMessage(delay, sender, receiver, msg, extraInfo);
}

void AIObject::PursueTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.PursueTarget(pos, vel, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), aiTimeElapsed);

		Position = pos.ToGLM();
		Velocity = vel.ToGLM();
	}
}

void AIObject::FleeTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.FleeTarget(pos, vel, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), Velocity.length(), 10 / (Velocity.length() + 1), aiTimeElapsed);

		Position = pos.ToGLM();
		Velocity = vel.ToGLM();
	}
}

void AIObject::EvadeTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.EvadeTarget(pos, pos, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), aiTimeElapsed);
	}
}

void AIObject::Wander()
{
	movementFunctions.SetWander(5, 2, 2);

	Vector2D pos(Position);
	Vector2D vel(Velocity);

	movementFunctions.Wander(pos, vel, aiTimeElapsed);

	Position = pos.ToGLM();
	Velocity = vel.ToGLM();
}

bool AIObject::CanViewTarget()
{
	return movementFunctions.CanSeeTarget(Vector2D(Position), Vector2D(Velocity), Vector2D(target->GetPosition()), 100, 60);
}