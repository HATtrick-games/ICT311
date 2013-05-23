/**
 * \file	CollisionBody.h
 *
 * \brief	Declares the collision body class.
 */
#include <btBulletDynamicsCommon.h>
#include "CollisionWorldSingleton.h"
//#include "CommonFuncs.h"
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
	 * \fn	void CollisionBody::createplane(glm::vec3 Pos, glm::vec3 normal);
	 *
	 * \brief	Createplanes.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \param	Pos   	The position.
	 * \param	normal	The normal.
	 */

	void createplane(glm::vec3 Pos, glm::vec3 normal);

	/**
	*\brief creates a rigid body that is square and can't be moved
	*
	*/
	void CreateRigidBody(glm::vec3 pos, float x, float y, float z, int nothing);

	/**
	 * \fn	void CollisionBody::CreateRigidBody(glm::vec3 pos, float x, float y, float z,
	 * 		std::string word);
	 *
	 * \brief	Creates a square rigid body that can be moved around
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \param	pos 	The position.
	 * \param	x   	The x coordinate.
	 * \param	y   	The y coordinate.
	 * \param	z   	The z coordinate.
	 * \param	word	The word.
	 */

	void CreateRigidBody(glm::vec3 pos, float x, float y, float z, std::string word);

	/**
	*\brief Update function that will ensure a collision body stays activated
	*
	*/
	void Update();

	/**
	*\brief rotate functions that will rotate the current collision body by the amount of degrees passed in
	*
	*/
	void Rotate(float degrees);

	/**
	 * \brief	The swap.
	 */

	int swap;

	/**
	 * \fn	CollisionBody::CollisionBody(glm::vec3 Position, glm::vec3 Normal);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	Position	The position x coordinate.
	 * \param	Normal  	The position y coordinate.
	 */

	CollisionBody(glm::vec3 Position, glm::vec3 Normal);

	/**
	*\brief constructer that can pick what type of collision body
	*
	*/
	CollisionBody(glm::vec3 Position, int type);

	/**
	 * \fn	CollisionBody::CollisionBody(glm::vec3 Position, float length, float width, float height);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \param	Position	The position.
	 * \param	length  	The length.
	 * \param	width   	The width.
	 * \param	height  	The height.
	 */

	CollisionBody(glm::vec3 Position, float length, float width, float height);

	/**
	 * \fn	CollisionBody::CollisionBody(glm::vec3 Position, float length, float width, float height,
	 * 		std::string word);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \param	Position	The position.
	 * \param	length  	The length.
	 * \param	width   	The width.
	 * \param	height  	The height.
	 * \param	word		The word.
	 */

	CollisionBody(glm::vec3 Position, float length, float width, float height, std::string word);

	/**
	 * \fn	CollisionBody::CollisionBody(glm::vec3 Position, float length, float width, float height,
	 * 		int nothing);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \param	Position	The position.
	 * \param	length  	The length.
	 * \param	width   	The width.
	 * \param	height  	The height.
	 * \param	nothing 	The nothing.
	 */

	CollisionBody(glm::vec3 Position, float length, float width, float height,int nothing);

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
	 * \fn	void CollisionBody::SetXVelocity(float velocityX);
	 *
	 * \brief	Sets the velocity of the xz direction y direction is taken from gravity.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	velocityX	The velocity x coordinate.
	 */

	void SetXVelocity(float velocityX);

	/**
	*\brief will set Z velocity and leave other velocities untouched
	*
	*/
	void SetZVelocity(float velocityY);

	/**
	*\brief returns the y value of the bodies velocity
	*
	*/
	float ReturnYVelocity();



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
	 * \brief	Gets the position.
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

	glm::vec3 GetPosition();
protected:
private:

	/**
	 * \fn	void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fRadius);
	 *
	 * \brief	Creates sphere rigid body.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	passPos	The position x coordinate.
	 * \param	fRadius	The radius.
	 */

	void CreateRigidBody(glm::vec3 passPos, float fRadius);

	/**
	 * \fn	void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fXdis, float fYdis,
	 * 		float fZdis);
	 *
	 * \brief	Creates a square rigid body.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	passPos	The position x coordinate.
	 * \param	fXdis  	The xdis.
	 * \param	fYdis  	The ydis.
	 * \param	fZdis  	The zdis.
	 */

	void CreateRigidBody(glm::vec3 passPos, float fXdis, float fYdis, float fZdis);

	 /**
	  * \property	* brief The current position. */ glm::vec3 CurrentPosition;

	 


	
};