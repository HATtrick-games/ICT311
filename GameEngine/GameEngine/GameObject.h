#include "CommonFuncs.h"

class GameObject
{
public:
	
	virtual void Intialise();
	virtual void Update() = 0;
	const float* GetModel();
	const int GetModelSize();
	void SetModel(float* pmodel);
	void SetModelsize(int size);
	CommonFunctions::Pos GetPosition();

protected:


private:
	float *pModel;
	int iModelSize;
	float fScale;
	float fRotation;
	CommonFunctions::Pos stPosition;
	GameObject();

}