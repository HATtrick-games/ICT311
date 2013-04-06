#pragma once

#include "CommonFuncs.h"

class GameObject
{
public:
	GameObject();
	
	virtual void Initialise();
	virtual void Update() = 0;
	const float* GetModel();
	const int GetModelSize();
	void SetModel(float* Model);
	void SetModelsize(int size);
	void SetstPosition(CommonFunctions::Pos newPos);
	CommonFunctions::Pos GetPosition();

protected:


private:
	float *pModel;
	int iModelSize;
	float fScale;
	float fRotation;
	CommonFunctions::Pos stPosition;
	

};