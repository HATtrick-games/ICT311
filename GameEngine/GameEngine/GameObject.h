#pragma once

#include "CommonFuncs.h"
#include "CollisionBody.h"

class GameObject
{
public:
	GameObject();
	GameObject(float fXposition, float fYposition, float fZposition);
	GameObject(std::string assetfile, float fXposition, float fYposition, float fZposition);
	
	virtual void Initialise();
	virtual void Update();
	const float* GetModel();
	const int GetModelSize();
	std::string GetAssetFile();
	void SetModel(float* Model);
	void SetModelsize(int size);
	void SetPosition(CommonFunctions::Pos newPos);
	void SetPosition(float x, float y, float z);
	void SetAssetFile(std::string file);
	CommonFunctions::Pos GetPosition();

	void ChangePosition(float x, float y, float z);

protected:
	CollisionBody* cbCollisionObject;

private:
	float *pModel;
	int iModelSize;
	float fScale;
	float fRotation;
	CommonFunctions::Pos stPosition;
	

	std::string* assetFilename;
};