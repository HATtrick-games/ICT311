#pragma once


#include "CollisionBody.h"
#include "glm\glm.hpp"

class GameObject
{
public:
	GameObject();
	GameObject(float fXposition, float fYposition, float fZposition);
	//GameObject(std::string assetfile, float fXposition, float fYposition, float fZposition);
	
	virtual void Initialise();
	virtual void Update();
	const float* GetModel();
	const int GetModelSize();
	//std::string GetAssetFile();
	void SetModel(float* Model);
	void SetModelsize(int size);
	virtual void SetPosition(glm::vec3 newPos);
	void SetPosition(float x, float y, float z);
	//void SetAssetFile(std::string file);
	glm::vec3 GetPosition();

	void ChangePosition(float x, float y, float z);

protected:
	CollisionBody* cbCollisionObject;
	glm::vec3 stPosition;
private:
	float *pModel;
	int iModelSize;
	float fScale;
	float fRotation;
	
	

	//std::string* assetFilename;
};