/***CollisionWorld.cpp**/
#include"stdafx.h"
#include"CollisionWorldSingleton.h"

CollisionWorldSingleton* CollisionWorldSingleton::Instance()
{
	static CollisionWorldSingleton instance;

	return &instance;
}

void CollisionWorldSingleton::AddRigidBody(btRigidBody* RigidBody)
{
	cout<<"ADDED";
	DynamicsWorld->addRigidBody(RigidBody);
}

void CollisionWorldSingleton::StepWorld()
{
	stepped = true;
	
	DynamicsWorld->stepSimulation(1/1000.f, 100);
}

void CollisionWorldSingleton::SetGravity(float y)
{
	DynamicsWorld->setGravity(btVector3(0,y,0));
}

bool CollisionWorldSingleton::Stepped()
{
	return stepped;
}

