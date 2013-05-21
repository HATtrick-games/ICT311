#pragma once


#include "CollisionBody.h"
#include "glm\glm.hpp"
#include "Mesh.h"

class GameObject
{
public:
	GameObject();
	glm::vec3 GetPosition();
	glm::vec3 GetVelocity(); 
	void SetVelocity(glm::vec2 Velocity);
	void SetMesh(Mesh* passmesh);
	Mesh* GetMesh();
	virtual void InitialiseCollisionBody(glm::vec3 Pos);
	virtual void Update(){};// = 0;

protected:
	Mesh* ObjectMesh;
	CollisionBody* cbCollisionObject;
	glm::vec3 Position;
	glm::vec3 Velocity;

private:
};