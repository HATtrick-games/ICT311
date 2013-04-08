#include "GameObject.h"


GameObject::GameObject()
{
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

void GameObject::SetstPosition(CommonFunctions::Pos newPos)
{
	stPosition = newPos;
}