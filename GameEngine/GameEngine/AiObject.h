#pragma once
//#include <string>
#include "GameObject.h"

class AiObject :public GameObject
{
public:
	AiObject();

	virtual void Initialise();
	virtual void Update();
protected:
private:
	int iHealth;
	

};