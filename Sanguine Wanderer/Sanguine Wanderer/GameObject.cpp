#include"stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	
}

glm::vec3 GameObject::GetPosition()
{
	return Position;
}

void GameObject::InitialiseCollisionBody(glm::vec3 Pos)
{
	cbCollisionObject = new CollisionBody(Pos);
}

void GameObject::SetVelocity(glm::vec2 velocitypass)
{
	cbCollisionObject->SetVelocityGravity(velocitypass.x,velocitypass.y);
}