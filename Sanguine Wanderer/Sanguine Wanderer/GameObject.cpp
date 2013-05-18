#include "GameObject.h"


GameObject::GameObject()
{
	
}

GameObject::GameObject(float fXpos, float fYpos, float fZpos)
{
	

}

/*
GameObject::GameObject(std::string assetfile, float fXpos, float fYpos, float fZpos)
{
	
}*/

void GameObject::Initialise()
{

}

void GameObject::Update()
{

}

void GameObject::SetModel(float* Model)
{
	
}

void GameObject::SetModelsize(int passsize)
{
	
}

glm::vec3 GameObject::GetPosition()
{
	
	return stPosition;
}

void GameObject::SetPosition(glm::vec3 newPos)
{
	
}

void GameObject::SetPosition(float x, float y, float z)
{
	
}

void GameObject::ChangePosition(float x, float y, float z)
{
	
}

/*
std::string GameObject::GetAssetFile()
{
	return *assetFilename;
}

void GameObject::SetAssetFile(std::string file)
{
	//std::cout << "Setting Asset File " << file << std::endl;
	assetFilename = &file;
}*/