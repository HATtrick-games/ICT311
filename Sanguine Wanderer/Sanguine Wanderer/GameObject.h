/**
 * \file	GameObject.h
 *
 * \brief	Declares the game object class.
 */

#pragma once

#include "Animation.h"
#include "CollisionBody.h"
#include "glm\glm.hpp"
#include "Mesh.h"

/**
 * \class	GameObject
 *
 * \brief	Game object.
 *
 * \author	Wise Bear
 * \date	5/23/2013
 */

class GameObject
{
public:
	/**
	*\brief default constructer
 	*
	*/
	GameObject();

	/**
	*\brief returns position of object
	*
	*/
	glm::vec3 GetPosition();

	/**
	*\brief returns velocity of object
	*
	*/
	glm::vec3 GetVelocity(); 

	/**
	*\brief returns scale of object
	*
	*/
	glm::vec3 GetScale();

	/**
	*\brief returns rotation of object
	*
	*/
	glm::vec3 GetRotation();

	/**
	*\brief sets velocity of object
	*
	*/
	void SetVelocity(glm::vec2 Velocity);

	/**
	*\brief sets the model mesh for the object
	*
	*/
	void SetMesh(Mesh* passmesh);

	/**
	*\brief sets the position of the object
	*
	*/
	void SetPosition(glm::vec3 NewPos);

	/**
	*\brief sets the scale of the object
	*
	*/
	void SetScale(glm::vec3 NewScale);

	/**
	*\brief sets the rotation of the object
	*
	*/
	void SetRotation(glm::vec3 NewRotation);

	/**
	*\brief sets the animation for the object
	*
	*/
	void SetAnimations(Animation * NewAnimations);

	/**
	 * \fn	Animation* GameObject::GetAnimations();
	 *
	 * \brief	Gets the animations.
	 *
	 * \author	Wise Bear
	 * \date	5/23/2013
	 *
	 * \return	null if it fails, else the animations.
	 */

	Animation* GetAnimations();

	/**
	*\brief returns is animating boolean
	*
	*/
	bool GetIsAnimating();

	/**
	*\brief toggles the animating bool
	*
	*/
	void ToggleIsAnimating();

	/**
	*\brief returns the object mesh
	*
	*/
	Mesh* GetMesh();

	/**
	*\brief intialises the collision body for this object
	*
	*/
	virtual void InitialiseCollisionBody();

	/**
	*\brief virtual update function for game object, lines up collision body with rendering position
	*
	*/
	virtual void Update();// = 0;

protected:
	/**
	*\brief The object mesh
	*
	*/
	Mesh* ObjectMesh;

	/**
	*\brief The collision Object
	*
	*/
	CollisionBody* cbCollisionObject;

	/**
	 * \brief	The position.
	 */

	glm::vec3 Position;

	/**
	*\brief the object scale
	*
	*/
	glm::vec3 Scale;

	/**
	 * \brief	The rotation.
	 */

	glm::vec3 Rotation;

	/**
	*\brief the object velocity
	*
	*/
	glm::vec3 Velocity;

	/**
	 * \brief	The mesh center.
	 */

	glm::vec3 MeshCenter;

	/**
	*\brief the animations for this object
	*
	*/

	Animation * Animations;

	/**
	 * \brief	true if this object is animating.
	 */

	bool IsAnimating;

private:
};