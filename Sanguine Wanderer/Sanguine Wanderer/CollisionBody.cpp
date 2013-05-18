#include "stdafx.h"
#include "CollisionBody.h"

CollisionBody::CollisionBody(glm::vec3 passPosition)
{
	CurrentPosition.x = passPosition.x;
	CurrentPosition.y = passPosition.y;
	CurrentPosition.z = passPosition.z;
	CreateRigidBody(passPosition, 1);
	//CreateRigidBody(10,10,10,1);
	//std::cout<<"MAKINGGGGGGGGGGGGGGGGGGGG";
}

void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fRadius)
{
	CollisionShape = new btSphereShape(1);
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(passPos.x,passPos.y,passPos.z)));
    btScalar mass = 0.1;
    btVector3 fallInertia(1,1,1);
    CollisionShape->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo ShapeRigidBodyCI(mass,MotionState,CollisionShape,fallInertia);
    ThisRigidBody = new btRigidBody(ShapeRigidBodyCI);
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    
}

void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fXdis, float fYdis, float fZdis)
{
	CollisionShape = new btBoxShape(btVector3(fXdis, fYdis, fZdis));
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(passPos.x,passPos.y,passPos.z)));
    btScalar mass = 0.1;
    btVector3 fallInertia(1,1,1);
    CollisionShape->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo ShapeRigidBodyCI(mass,MotionState,CollisionShape,fallInertia);
    ThisRigidBody = new btRigidBody(ShapeRigidBodyCI);
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    

}


void CollisionBody::SetCollisionPos(float x, float y, float z)
{
	
	ThisRigidBody->translate(btVector3(x-CurrentPosition.x, y-CurrentPosition.y, z-CurrentPosition.z));
	CurrentPosition.x = x;
	CurrentPosition.y = y;
	CurrentPosition.z = z;
}


void CollisionBody::ApplyForce(float x, float y, float z)
{
	ThisRigidBody->applyCentralForce(btVector3(x,y,z));
}

void CollisionBody::SetVelocity(float velocityX, float velocityY, float velocityZ)
{
	ThisRigidBody->setLinearVelocity(btVector3(velocityX, velocityY, velocityZ));
}

void CollisionBody::SetVelocityGravity(float velocityX, float velocityZ)
{
	ThisRigidBody->setLinearVelocity( btVector3(velocityX, ThisRigidBody->getLinearVelocity().getY() , velocityZ));
}

void CollisionBody::TranslateObject(float fTransX, float fTransY, float fTransZ)
{
	CurrentPosition.x += fTransX;
	CurrentPosition.y += fTransY;
	CurrentPosition.z += fTransZ;
	ThisRigidBody->translate(btVector3(fTransX, fTransY, fTransZ));
}

void CollisionBody::ScaleObject(float fScaleX, float fScaleY, float fScaleZ)
{
	ThisRigidBody->getCollisionShape()->setLocalScaling(btVector3(fScaleX, fScaleY, fScaleZ));
}


glm::vec3 CollisionBody::GetPosition()
{	
	ThisRigidBody->getMotionState()->getWorldTransform(trans);
	CurrentPosition.x = trans.getOrigin().getX();
	CurrentPosition.y = trans.getOrigin().getY();
	CurrentPosition.z = trans.getOrigin().getZ();
		
	return CurrentPosition;
}


