/***CollisionWorld.cpp**/
#include "CollisionWorldSingleton.h"

CollisionWorldSingleton* CollisionWorldSingleton::Instance()
{
	static CollisionWorldSingleton instance;

	return &instance;
}

void CollisionWorldSingleton::AddRigidBody(btRigidBody* RigidBody)
{
	DynamicsWorld->addRigidBody(RigidBody);
}

void CollisionWorldSingleton::StepWorld()
{
	DynamicsWorld->stepSimulation(1/60.f, 10);
}
