#include "CollisionWorldSingleton.h"
#include "CommonFuncs.h"
#pragma once
class CollisionBody
{
private:
	CollisionBody();
	void CreateRigidBody();
	void ApplyForce(float x, float y, float z);
	CommonFunctions::Pos GetPosition();

	btRigidBody* ThisRigidBody;
	btTransform trans;
	CommonFunctions::Pos CurrentPosition;
public:
};