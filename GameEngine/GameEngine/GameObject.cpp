#include "GameObject.h"

GameObject::GameObject()
{

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