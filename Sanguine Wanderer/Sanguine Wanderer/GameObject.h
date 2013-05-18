#pragma once


#include "CollisionBody.h"
#include "glm\glm.hpp"

class GameObject
{
public:
	GameObject();
	glm::vec3 GetPosition();
	virtual void Update() = 0;

protected:
	CollisionBody* cbCollisionObject;
	glm::vec3 Position;

private:
	
	
	

};