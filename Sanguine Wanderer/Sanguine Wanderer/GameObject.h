#pragma once

#include "Animation.h"
#include "CollisionBody.h"
#include "glm\glm.hpp"
#include "Mesh.h"

class GameObject
{
public:
	GameObject();
	glm::vec3 GetPosition();
	glm::vec3 GetVelocity(); 
	glm::vec3 GetScale();
	glm::vec3 GetRotation();
	void SetVelocity(glm::vec2 Velocity);
	void SetMesh(Mesh* passmesh);
	void SetPosition(glm::vec3 NewPos);
	void SetScale(glm::vec3 NewScale);
	void SetRotation(glm::vec3 NewRotation);
	void SetAnimations(Animation * NewAnimations);
	Animation* GetAnimations();
	bool GetIsAnimating();
	void ToggleIsAnimating();

	Mesh* GetMesh();
	virtual void InitialiseCollisionBody();
	virtual void Update();// = 0;

protected:
	Mesh* ObjectMesh;
	CollisionBody* cbCollisionObject;
	glm::vec3 Position;
	glm::vec3 Scale;
	glm::vec3 Rotation;
	glm::vec3 Velocity;
	glm::vec3 MeshCenter;

	Animation * Animations;
	bool IsAnimating;

private:
};