#include "stdafx.h"
#include "CollisionBody.h"

CollisionBody::CollisionBody(glm::vec3 passPosition,float length, float width, float height)
{
	trans.setIdentity();
	trans.setOrigin(btVector3(0,0,0));
	CurrentPosition.x = passPosition.x;
	CurrentPosition.y = passPosition.y;
	CurrentPosition.z = passPosition.z;
	swap = 0;
	CreateRigidBody(passPosition, length,width,height);
}

CollisionBody::CollisionBody(glm::vec3 passPosition,float length, float width, float height, int nothing)
{
	trans.setIdentity();
	trans.setOrigin(btVector3(0,0,0));
	CurrentPosition.x = passPosition.x;
	CurrentPosition.y = passPosition.y;
	CurrentPosition.z = passPosition.z;
	swap = 0;
	CreateRigidBody(passPosition, length,width,height, nothing);
}

CollisionBody::CollisionBody(glm::vec3 passPosition,glm::vec3 Normal)
{
	cout<<">>>>>>>>>>>>>>>>>>>>>>PLANE CREATED>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	
	
	createplane(passPosition, Normal);
}
void CollisionBody::Rotate(float degrees)
{
	//not implemented
}

CollisionBody::CollisionBody(glm::vec3 passPosition, int type)
{
	trans.setIdentity();
	trans.setOrigin(btVector3(0,0,0));
	CurrentPosition.x = passPosition.x;
	CurrentPosition.y = passPosition.y;
	CurrentPosition.z = passPosition.z;
	swap = 0;
	  
	if(type == 1)
	{
		cout<<"type 1";
	CreateRigidBody(passPosition, 2);
	}
	else if(type == 3)
	{
		//createplane();
	}
	else
	{
		cout<<"type2";
	CreateRigidBody(passPosition, 10,10,10);
	}
		
}

float CollisionBody::ReturnYVelocity()
{
	return ThisRigidBody->getLinearVelocity().getY();
}

void CollisionBody::Update()
{
	ThisRigidBody->setActivationState(DISABLE_DEACTIVATION);
	
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

void CollisionBody::createplane(glm::vec3 passpos, glm::vec3 normal)
{
	CollisionShape = new btStaticPlaneShape(btVector3(normal.x,normal.y,normal.z),1);
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-10000,0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI2(0,MotionState,CollisionShape,btVector3(0,0,0));
	ThisRigidBody = new btRigidBody(groundRigidBodyCI2);
	//trans.setOrigin(btVector3(passpos.x,passpos.y,passpos.z));
	//ThisRigidBody->setWorldTransform(trans);
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    
	

	

}

void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fXdis, float fYdis, float fZdis, int nothing)
{

	CollisionShape = new btBoxShape(btVector3(fXdis, fYdis, fZdis));
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(passPos.x,passPos.y,passPos.z)));
    btScalar mass = 0;
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
    btScalar mass = 0;
    btVector3 fallInertia(1,1,1);
    CollisionShape->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo ShapeRigidBodyCI(mass,MotionState,CollisionShape,fallInertia);
    ThisRigidBody = new btRigidBody(ShapeRigidBodyCI);
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    

}


void CollisionBody::SetCollisionPos(float x, float y, float z)
{
	//not implemented	
}


void CollisionBody::ApplyForce(float x, float y, float z)
{
	
	ThisRigidBody->applyCentralForce(btVector3(x,y,z));
	
}

void CollisionBody::SetVelocity(float velocityX, float velocityY, float velocityZ)
{
	ThisRigidBody->setLinearVelocity(btVector3(velocityX, velocityY, velocityZ));
}

void CollisionBody::SetXVelocity(float velocityX)
{
	ThisRigidBody->setLinearVelocity(btVector3(velocityX,ThisRigidBody->getLinearVelocity().getY(),ThisRigidBody->getLinearVelocity().getZ()));
}

void CollisionBody::SetZVelocity(float velocityZ)
{
	ThisRigidBody->setLinearVelocity(btVector3(ThisRigidBody->getLinearVelocity().getX(),ThisRigidBody->getLinearVelocity().getY(),velocityZ));
}

void CollisionBody::SetVelocityGravity(float velocityX, float velocityZ)
{
	ThisRigidBody->setLinearVelocity( btVector3(velocityX, ThisRigidBody->getLinearVelocity().getY() , velocityZ));
}

void CollisionBody::TranslateObject(float fTransX, float fTransY, float fTransZ)
{
	
}

void CollisionBody::ScaleObject(float fScaleX, float fScaleY, float fScaleZ)
{
	//not implemented	
}


glm::vec3 CollisionBody::GetPosition()
{	
	ThisRigidBody->getMotionState()->getWorldTransform(trans);
	CurrentPosition.x = trans.getOrigin().getX();
	CurrentPosition.y = trans.getOrigin().getY();
	CurrentPosition.z = trans.getOrigin().getZ();
		
	return CurrentPosition;
}


