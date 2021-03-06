#include"stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	ObjectMesh = 0;
	Position = glm::vec3(0,0,0);
	IsAnimating = false;
}

glm::vec3 GameObject::GetPosition()
{
	//Position = (cbCollisionObject->GetPosition()-MeshCenter);
	
	return Position;
}

glm::vec3 GameObject::GetVelocity()
{
	return Velocity;
}

void GameObject::InitialiseCollisionBody()
{
	MeshCenter.x = (((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())/2)+ObjectMesh->GetMinX());
	MeshCenter.y = (((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())/2)+ObjectMesh->GetMinY());
	MeshCenter.z = (((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())/2)+ObjectMesh->GetMinZ());

	MeshCenter.x = MeshCenter.x*Scale.x;
	MeshCenter.y = MeshCenter.y*Scale.y;
	MeshCenter.z = MeshCenter.z*Scale.z;
	MeshCenter.x += Position.x;
	MeshCenter.y += Position.y;
	MeshCenter.z += Position.z;

	
	//cout<<"\n  DISTANCES=="<<((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())*Scale.x)<<"=="<<((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())*Scale.y)<<"=="<<((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())*Scale.z)<<"\n";
	//cout<<"  \n  MeshCenter"<<MeshCenter.x<<"--/"<<MeshCenter.y<<"--/"<<MeshCenter.z<<"\n";
	cbCollisionObject = new CollisionBody(MeshCenter,(((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())*Scale.x)/2)*1.1,(((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())*Scale.y)/2)*1.1,(((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())*Scale.z)/2)*1.1);
	
	MeshCenter.x -= Position.x;
	MeshCenter.y -= Position.y;
	MeshCenter.z -= Position.z;
	//cbCollisionObject->Rotate(180);
}
void GameObject::Update()
{
	cbCollisionObject->Update();
	Position = cbCollisionObject->GetPosition();
	Position.x -= MeshCenter.x;
	Position.y -= MeshCenter.y;
	Position.z -= MeshCenter.z;
	cbCollisionObject->Update();

}

void GameObject::SetVelocity(glm::vec2 velocitypass)
{
	//std::cout << "Setting velocity " << velocitypass.x << " " << velocitypass.y << std::endl;
	cbCollisionObject->SetVelocityGravity(velocitypass.x,velocitypass.y);
}

void GameObject::SetMesh(Mesh* passmesh)
{
	ObjectMesh = passmesh;
	
	
}

Mesh* GameObject::GetMesh()
{
	return ObjectMesh;
}

void GameObject::SetPosition(glm::vec3 NewPos)
{
	
	Position = NewPos;
	//cout<<"\n ====="<<Position.x<<"    "<<Position.y<<"  "<<Position.z<<"\n";
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

void GameObject::SetAnimations(Animation * NewAnimations)
{
	Animations = NewAnimations;
}

Animation * GameObject::GetAnimations()
{
	return Animations;
}

bool GameObject::GetIsAnimating()
{
	return IsAnimating;
}

void GameObject::ToggleIsAnimating()
{
	IsAnimating = !IsAnimating;
}