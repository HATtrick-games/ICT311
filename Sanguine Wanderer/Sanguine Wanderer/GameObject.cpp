#include"stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	ObjectMesh = 0;
	Position = glm::vec3(0,0,0);
}

glm::vec3 GameObject::GetPosition()
{
	//Position = cbCollisionObject->GetPosition()-MeshCenter;
	return Position;
}

void GameObject::InitialiseCollisionBody(glm::vec3 Pos)
{

	cbCollisionObject = new CollisionBody(Pos+MeshCenter,MeshCenter.x,MeshCenter.y, MeshCenter.z);
}

void GameObject::SetVelocity(glm::vec2 velocitypass)
{
	cbCollisionObject->SetVelocityGravity(velocitypass.x,velocitypass.y);
}

void GameObject::SetMesh(Mesh* passmesh)
{

	ObjectMesh = passmesh;
	MeshCenter.x = (ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())/2;
	MeshCenter.y = (ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())/2;
	MeshCenter.z = (ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())/2;
}

Mesh* GameObject::GetMesh()
{
	return ObjectMesh;
}

void GameObject::SetPosition(glm::vec3 NewPos)
{
	Position = NewPos;
}

void GameObject::SetScale(glm::vec3 NewScale)
{
	Scale = NewScale;
}

void GameObject::SetRotation(glm::vec3 NewRotation)
{
	Rotation = NewRotation;
}

glm::vec3 GameObject::GetRotation()
{
	return Rotation;
}

glm::vec3 GameObject::GetScale()
{
	return Scale;
}