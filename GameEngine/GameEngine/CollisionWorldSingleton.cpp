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
	stepped = true;
	DynamicsWorld->stepSimulation(1/60.f, 10);
}

void CollisionWorldSingleton::SetGravity(float y)
{
	 DynamicsWorld->setGravity(btVector3(0,y,0));
}

bool CollisionWorldSingleton::Stepped()
{
	return stepped;
}

