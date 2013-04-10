#include "CollisionWorldSingleton.h"
#include "CommonFuncs.h"
#include "glm\glm.hpp"
#pragma once
class CollisionBody
{
public:
	CollisionBody(float fPosX, float fPosY, float fPosZ);
	
	void ApplyForce(float x, float y, float z);
	void SetVelocity(float velocityX, float velcoityY, float velocityZ);
	void SetVelocityGravity(float velocityX, float veclocityZ);
	void TranslateObject(float fTransX, float fTransY, float fTransZ);
	void ScaleObject(float fScaleX, float fScaleY, float fScaleZ);
	void SetCollisionPos(float x, float y, float z);
	glm::vec3 GetPosition();
protected:
private:
	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fRadius);
	void CreateRigidBody(float fPosX, float fPosY, float fPosZ, float fXdis, float fYdis, float fZdis);
	btRigidBody* ThisRigidBody;
	btCollisionShape* CollisionShape;
	btDefaultMotionState* MotionState;
	btTransform trans;
	glm::vec3 CurrentPosition;


	
};