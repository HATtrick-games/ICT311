#include"stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	
}

glm::vec3 GameObject::GetPosition()
{
	Position = cbCollisionObject->GetPosition()-MeshCenter;
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