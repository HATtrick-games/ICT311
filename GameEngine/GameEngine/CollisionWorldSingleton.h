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
		 dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
	}
	
	btDiscreteDynamicsWorld* dynamicsWorld;
public:
	//~CollisionWorldSingleton();
	static CollisionWorldSingleton* Instance();
};


#endif