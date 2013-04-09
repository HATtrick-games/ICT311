#pragma once
#include "GameObject.h"


class PlayerObject :public GameObject
{
public:
	PlayerObject();
	~PlayerObject(){};
	void SetPlayerVelocity(float x, float z);

	virtual void Initialise();
	virtual void Update();
protected:
private:

};