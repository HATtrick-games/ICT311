/*Collision World Class, this class stores the collision world object and contains functions for manipulating it.*/
#pragma once
#include <btBulletDynamicsCommon.h>
#ifndef COLLISION_WORLD_SINGLETON
#define COLLISION_WORLD_SINGLETON

class CollisionWorldSingleton
{
private:
	
	CollisionWorldSingleton()
	{
		 btBroadphaseInterface* broadphase = new btDbvtBroadphase();
		 btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
		 btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
		 btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
		 DynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
		 DynamicsWorld->setGravity(btVector3(0,0,0));
		 
	}
	
	btDiscreteDynamicsWorld* DynamicsWorld;
public:

	void AddRigidBody(btRigidBody* RigidBody);
	void StepWorld();
	void SetGravity(float y);
	//~CollisionWorldSingleton(){};
	static CollisionWorldSingleton* Instance();
};


#endif;