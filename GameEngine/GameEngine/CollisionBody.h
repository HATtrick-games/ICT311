#include "CollisionWorldSingleton.h"
#include "CommonFuncs.h"
#pragma once
class CollisionBody
{
public:
	CollisionBody(float fPosX, float fPosY, float fPosZ);
	
	void ApplyForce(float x, float y, float z);
	void SetVelocity(float velocityX, float velcoityY, float velocityZ);
	void SetVelocityGravity(float velocityX, float veclocityZ);
	CommonFunctions::Pos GetPosition();
protected:
private:
	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fRadius);
	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fXdis, float fYdis, float fZdis);
	btRigidBody* ThisRigidBody;
	btCollisionShape* CollisionShape;
	btDefaultMotionState* MotionState;
	btTransform trans;
	CommonFunctions::Pos CurrentPosition;


	
};