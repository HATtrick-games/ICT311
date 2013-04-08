#include "CollisionWorldSingleton.h"
#include "CommonFuncs.h"
#pragma once
class CollisionBody
{
public:
	CollisionBody();
	void CreateRigidBody();
	void ApplyForce(float x, float y, float z);
	void SetVelocity(float velocityX, float velcoityY, float velocityZ);
	void SetVelocityGravity(float velocityX, float veclocityZ);
	CommonFunctions::Pos GetPosition();
protected:
private:
	btRigidBody* ThisRigidBody;
	btTransform trans;
	CommonFunctions::Pos CurrentPosition;


	
};