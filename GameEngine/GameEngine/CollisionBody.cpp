#include "CollisionBody.h"

CollisionBody::CollisionBody()
{
	CreateRigidBody();
}

void CollisionBody::CreateRigidBody()
{
	btCollisionShape* Sphere = new btSphereShape(1);
	btDefaultMotionState* SphereMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,10,0)));
    btScalar mass = 0.1;
    btVector3 fallInertia(1,1,1);
    Sphere->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo SphereRigidBodyCI(mass,SphereMotionState,Sphere,fallInertia);
    ThisRigidBody = new btRigidBody(SphereRigidBodyCI);
	CollisionWorldSingleton::Instance()->AddRigidBody(ThisRigidBody);    
}

void CollisionBody::ApplyForce(float x, float y, float z)
{
	ThisRigidBody->applyCentralForce(btVector3(x,y,z));
}



CommonFunctions::Pos CollisionBody::GetPosition()
{
	ThisRigidBody->getMotionState()->getWorldTransform(trans);
	CurrentPosition.x = trans.getOrigin().getX();
	CurrentPosition.y = trans.getOrigin().getY();
	CurrentPosition.z = trans.getOrigin().getZ();

	return CurrentPosition;
}

