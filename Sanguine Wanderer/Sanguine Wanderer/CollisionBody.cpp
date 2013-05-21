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

/*
btRigidBody * rigidBody = //...
btTransform tr;
tr.setIdentity();
btQuaternion quat;
quat.setEuler(yaw,pitch,roll); //or quat.setEulerZYX depending on the ordering you want
tr.setRotation(quat);*/

//rigidBody->setCenterOfMassTransform(tr);

void CollisionBody::Rotate(float degrees)
{
	/*
	cout<<"ROTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAATE";
	ThisRigidBody->getMotionState()->getWorldTransform(trans);
	btQuaternion quat;
	quat.setEuler(180,0,0);
	trans.setRotation(btQuaternion(0,1,0,3.141));
	cout<<"\n ROTATION === "<<trans.getRotation().getX()<<"=="<<trans.getRotation().getY()<<"=="<<trans.getRotation().getZ()<<"=="<<trans.getRotation().getW();
	ThisRigidBody->setCenterOfMassTransform(trans);
	*/
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
		createplane();
	}
	else
	{
		cout<<"type2";
	CreateRigidBody(passPosition, 10,10,10);
	}
	//CreateRigidBody(10,10,10,1);
	
}

float CollisionBody::ReturnYVelocity()
{
	return ThisRigidBody->getLinearVelocity().getY();
}

void CollisionBody::Update()
{
	ThisRigidBody->setActivationState(DISABLE_DEACTIVATION);

	if((ThisRigidBody->getLinearVelocity().getX() == 0 )&&(ThisRigidBody->getLinearVelocity().getY() == 0)&&(ThisRigidBody->getLinearVelocity().getZ() == 0))
	{
		/*ThisRigidBody->setLinearVelocity(btVector3(0,-0.00000001,0));
		CollisionWorldSingleton::Instance()->StepWorld();
		ThisRigidBody->setLinearVelocity(btVector3(0,0.00000001,0));
		CollisionWorldSingleton::Instance()->StepWorld();
		ThisRigidBody->setLinearVelocity(btVector3(0,0,0));
		CollisionWorldSingleton::Instance()->StepWorld();*/
	}
	
	
}

void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fRadius)
{
	std::cout<<"MAKINGGGGGGGGGGGGGGGGGGGG";
	CollisionShape = new btSphereShape(1);
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(passPos.x,passPos.y,passPos.z)));
    btScalar mass = 0.1;
    btVector3 fallInertia(1,1,1);
    CollisionShape->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo ShapeRigidBodyCI(mass,MotionState,CollisionShape,fallInertia);
    ThisRigidBody = new btRigidBody(ShapeRigidBodyCI);
	
	
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    
	
}

void CollisionBody::createplane()
{
	CollisionShape = new btStaticPlaneShape(btVector3(0,1,0),1);
	MotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-10,0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI2(0,MotionState,CollisionShape,btVector3(0,0,0));
	ThisRigidBody = new btRigidBody(groundRigidBodyCI2);

	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    
	trans.setOrigin(btVector3(0,5,0));
	ThisRigidBody->setWorldTransform(trans);
}

void CollisionBody::CreateRigidBody(glm::vec3 passPos, float fXdis, float fYdis, float fZdis)
{

	std::cout<<"MAKINGGGGGGGGGGGGGGGGGGGG";
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
	
	
}


void CollisionBody::ApplyForce(float x, float y, float z)
{
	
	ThisRigidBody->applyCentralForce(btVector3(x,y,z));
	
}

void CollisionBody::SetVelocity(float velocityX, float velocityY, float velocityZ)
{
	//cout<<velocityX/10;
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
	
	//ThisRigidBody->getCollisionShape()->setLocalScaling(btVector3(fScaleX, fScaleY, fScaleZ));
}


glm::vec3 CollisionBody::GetPosition()
{	
	ThisRigidBody->getMotionState()->getWorldTransform(trans);
	CurrentPosition.x = trans.getOrigin().getX();
	CurrentPosition.y = trans.getOrigin().getY();
	CurrentPosition.z = trans.getOrigin().getZ();
	//cout<<CurrentPosition.x<<CurrentPosition.y<<CurrentPosition.z<<"\n";
	//cout<<ThisRigidBody->getLinearVelocity().getY()<<"\n";
	//cout<<ThisRigidBody->getLinearVelocity().getX();
		
	return CurrentPosition;
}


