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

void GameObject::SetModel(float* Model)
{
	pModel = Model;
}

void GameObject::SetModelsize(int passsize)
{
	iModelSize = passsize;
}

CommonFunctions::Pos GameObject::GetPosition()
{
	return stPosition;
}

void GameObject::SetPosition(CommonFunctions::Pos newPos)
{
	stPosition = newPos;
}

void GameObject::SetPosition(float x, float y, float z)
{
	stPosition.x = x;
	stPosition.y = y;
	stPosition.z = z;
}

void GameObject::ChangePosition(float x, float y, float z)
{
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