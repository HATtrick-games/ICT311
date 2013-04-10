#include "GameObject.h"


GameObject::GameObject()
{
	assetFilename = NULL;

	stPosition.x = 0;
	stPosition.y = 0;
	stPosition.z = 0;
	cbCollisionObject = new CollisionBody(0, 0, 0);
}

GameObject::GameObject(float fXpos, float fYpos, float fZpos)
{
	stPosition.x = fXpos;
	stPosition.y = fYpos;
	stPosition.z = fZpos;
	cbCollisionObject = new CollisionBody(fXpos, fYpos, fZpos);

}

GameObject::GameObject(std::string assetfile, float fXpos, float fYpos, float fZpos)
{
	stPosition.x = fXpos;
	stPosition.y = fYpos;
	stPosition.z = fZpos;
	cbCollisionObject = new CollisionBody(fXpos, fYpos, fZpos);
	assetFilename = &assetfile;
}

void GameObject::Initialise()
{

}

void GameObject::Update()
{

}

void GameObject::SetModel(float* Model)
{
	pModel = Model;
}

void GameObject::SetModelsize(int passsize)
{
	iModelSize = passsize;
}

glm::vec3 GameObject::GetPosition()
{
	stPosition = cbCollisionObject->GetPosition();
	std::cout<<cbCollisionObject->GetPosition().x<<"\n"<<cbCollisionObject->GetPosition().y<<"\n"<<cbCollisionObject->GetPosition().z<<"\n *********** \n \n";
	//std::cout<<stPosition.x<<"\n"<<stPosition.y<<"\n"<<stPosition.z<<"\n *********** \n \n";
	return stPosition;
}

void GameObject::SetPosition(glm::vec3 newPos)
{
	float fx, fy, fz;
	fx =(newPos.x-stPosition.x);
	fy =(newPos.y-stPosition.y);
	fz =(newPos.z-stPosition.z);
	std::cout<<fx<<fy<<fz<<"******************************************HULLO \n";
	cbCollisionObject->TranslateObject(fx,fy,fz);
	//std::cout<<cbCollisionObject->GetPosition().x<<"\n"<<cbCollisionObject->GetPosition().y<<"\n"<<cbCollisionObject->GetPosition().z<<"\n *********** \n \n";
	stPosition = newPos;
}

void GameObject::SetPosition(float x, float y, float z)
{
	float fx, fy, fz;
	fx =(x-stPosition.x);
	fy =(y-stPosition.y);
	fz =(z-stPosition.z);
	//std::cout<<fx<<fy<<fz;
	cbCollisionObject->TranslateObject(fx,fy,fz);
	stPosition.x = x;
	stPosition.y = y;
	stPosition.z = z;
}

void GameObject::ChangePosition(float x, float y, float z)
{
	cbCollisionObject->TranslateObject(x,y,z);
	stPosition.x += x;
	stPosition.y += y;
	stPosition.z += z;
}

std::string GameObject::GetAssetFile()
{
	return *assetFilename;
}

void GameObject::SetAssetFile(std::string file)
{
	//std::cout << "Setting Asset File " << file << std::endl;
	assetFilename = &file;
}