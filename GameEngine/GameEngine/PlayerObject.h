#pragma once
#include "GameObject.h"


class PlayerObject :public GameObject
{
public:
	PlayerObject();
	~PlayerObject(){};

	virtual void Initialise();
	virtual void Update();
protected:
private:

};