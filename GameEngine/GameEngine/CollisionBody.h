/**
 * \file	CollisionBody.h
 *
 * \brief	Declares the collision body class.
 */

#include "CollisionWorldSingleton.h"
#include "CommonFuncs.h"
#include "glm\glm.hpp"
#pragma once

/**
 * \class	CollisionBody
 *
 * \brief	Collision body.
 *
 * \author	Arran Ford
 * \date	4/10/2013
 */

class CollisionBody
{
public:

	/**
	 * \fn	CollisionBody::CollisionBody(float fPosX, float fPosY, float fPosZ);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	fPosX	The position x coordinate.
	 * \param	fPosY	The position y coordinate.
	 * \param	fPosZ	The position z coordinate.
	 */

	CollisionBody(float fPosX, float fPosY, float fPosZ);

	/**
	 * \fn	void CollisionBody::ApplyForce(float x, float y, float z);
	 *
	 * \brief	Applies a force in xyz direction to the collision object.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	x	The x coordinate.
	 * \param	y	The y coordinate.
	 * \param	z	The z coordinate.
	 */

	void ApplyForce(float x, float y, float z);

	/**
	 * \fn	void CollisionBody::SetVelocity(float velocityX, float velcoityY, float velocityZ);
	 *
	 * \brief	Sets the velocity of the object in xyz direction.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	velocityX	The velocity x coordinate.
	 * \param	velcoityY	The velcoity y coordinate.
	 * \param	velocityZ	The velocity z coordinate.
	 */

	void SetVelocity(float velocityX, float velcoityY, float velocityZ);

	/**
	 * \fn	void CollisionBody::SetVelocityGravity(float velocityX, float veclocityZ);
	 *
	 * \brief	Sets the velocity of the xz direction y direction is taken from gravity.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	velocityX 	The velocity x coordinate.
	 * \param	veclocityZ	The veclocity z coordinate.
	 */

	void SetVelocityGravity(float velocityX, float veclocityZ);

	/**
	 * \fn	void CollisionBody::TranslateObject(float fTransX, float fTransY, float fTransZ);
	 *
	 * \brief	Translate object.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	fTransX	The trans x coordinate.
	 * \param	fTransY	The trans y coordinate.
	 * \param	fTransZ	The trans z coordinate.
	 */

	void TranslateObject(float fTransX, float fTransY, float fTransZ);

	/**
	 * \fn	void CollisionBody::ScaleObject(float fScaleX, float fScaleY, float fScaleZ);
	 *
	 * \brief	Scale object.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	fScaleX	The scale x coordinate.
	 * \param	fScaleY	The scale y coordinate.
	 * \param	fScaleZ	The scale z coordinate.
	 */

	void ScaleObject(float fScaleX, float fScaleY, float fScaleZ);

	/**
	 * \fn	void CollisionBody::SetCollisionPos(float x, float y, float z);
	 *
	 * \brief	Sets the position of the collision object.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	x	The x coordinate.
	 * \param	y	The y coordinate.
	 * \param	z	The z coordinate.
	 */

	void SetCollisionPos(float x, float y, float z);

	/**
	 * \fn	glm::vec3 CollisionBody::GetPosition();
	 *
	 * \brief	Gets the position.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \return	The position.
	 */

	glm::vec3 GetPosition();
protected:
private:

	/**
	 * \fn	void CollisionBody::CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fRadius);
	 *
	 * \brief	Creates sphere rigid body.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	fPosX  	The position x coordinate.
	 * \param	fPosY  	The position y coordinate.
	 * \param	fPosZ  	The position z coordinate.
	 * \param	fRadius	The radius.
	 */

	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fRadius);

	/**
	 * \fn	void CollisionBody::CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fXdis,
	 * 		float fYdis, float fZdis);
	 *
	 * \brief	Creates a square rigid body.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	fPosX	The position x coordinate.
	 * \param	fPosY	The position y coordinate.
	 * \param	fPosZ	The position z coordinate.
	 * \param	fXdis	The xdis.
	 * \param	fYdis	The ydis.
	 * \param	fZdis	The zdis.
	 */

	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fXdis, float fYdis, float fZdis);

	/**
	 * \brief	this rigid body.
	 */

	btRigidBody* ThisRigidBody;

	/**
	 * \brief	The collision shape.
	 */

	btCollisionShape* CollisionShape;

	/**
	 * \brief	State of the motion.
	 */

	btDefaultMotionState* MotionState;

	/**
	 * \brief	The trans.
	 */

	btTransform trans;

	/**
	 * \brief	The current position.
	 */

	glm::vec3 CurrentPosition;


	
};