/**
 * \file	CollisionWorldSingleton.h
 *
 * \brief	Declares the collision world singleton class.
 */


#pragma once
#include <btBulletDynamicsCommon.h>
#ifndef COLLISION_WORLD_SINGLETON

/**
 * \def	COLLISION_WORLD_SINGLETON
 *
 * \brief	A macro that defines collision world singleton.
 *
 * \author	Arran Ford
 * \date	4/10/2013
 */

#define COLLISION_WORLD_SINGLETON

/**
 * \class	CollisionWorldSingleton
 *
 * \brief	Collision world singleton.
 *
 * \author	Arran Ford
 * \date	4/10/2013
 */

class CollisionWorldSingleton
{
private:
	btDiscreteDynamicsWorld* DynamicsWorld;
	/**
	 * \fn	CollisionWorldSingleton::CollisionWorldSingleton()
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 */

	CollisionWorldSingleton()
	{
		 
		//cout<<"COLLISION WORLD";
		 btBroadphaseInterface* broadphase = new btDbvtBroadphase();
		 btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
		 btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
		 btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
		 DynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
		 DynamicsWorld->setGravity(btVector3(0,-60,0));
		 stepped = false;
	}

	/**
	 * \brief	true if the collision world has been stepped at all.
	 */

	bool stepped;

	/**
	 * \brief	The dynamics world all collision occurs in here.
	 */

	//btDiscreteDynamicsWorld* DynamicsWorld;
public:
	
	/**
	 * \fn	bool CollisionWorldSingleton::Stepped();
	 *
	 * \brief	returns the stepped boolean.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool Stepped();

	/**
	 * \fn	void CollisionWorldSingleton::AddRigidBody(btRigidBody* RigidBody);
	 *
	 * \brief	Adds a rigid body to the collision world.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param [in,out]	RigidBody	If non-null, the rigid body.
	 */

	void AddRigidBody(btRigidBody* RigidBody);

	/**
	 * \fn	void CollisionWorldSingleton::StepWorld();
	 *
	 * \brief	Steps the collision world world.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 */

	void StepWorld();

	/**
	 * \fn	void CollisionWorldSingleton::SetGravity(float y);
	 *
	 * \brief	Sets a gravity.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	y	The y coordinate.
	 */

	void SetGravity(float y);
	//~CollisionWorldSingleton(){};

	/**
	 * \fn	static CollisionWorldSingleton* CollisionWorldSingleton::Instance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else.
	 */

	static CollisionWorldSingleton* Instance();
};


#endif;