#include "stdafx.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject()
{


}

PlayerObject::PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector)
{
	angle = 0;
	lx = 0;
	lz= -1;
	Position = StartingLocation;
	LookAtLocation = StartingLookAt;
	UpVector = StartingUpVector;
	cbCollisionObject = new CollisionBody(Position);
	//CollisionBody* cbCollisionObject;

}

void PlayerObject::StopPlayer()
{
	
		cbCollisionObject->SetVelocityGravity(0,0);
		
}

void PlayerObject::MovePlayer(int Direction)
{
	//cbCollisionObject->SetVelocity(2,0,0);
	float speed = 10;
	switch (Direction)
	{
	case 1: 
		{
		cout << "Forward";
		cbCollisionObject->SetVelocityGravity(ForwardVector.x*speed,ForwardVector.y*speed);
		//cbCollisionObject->SetVelocity(0,0,-5);
		break;
		}
	case 2:
		{
		cout <<"Back";
		cbCollisionObject->SetVelocityGravity(ForwardVector.x*-1*speed,ForwardVector.y*-1*speed);
		//cbCollisionObject->SetVelocity(0,0,5);
		break;
		}
	case 3:
		{
		cout <<"Left";
		cbCollisionObject->SetVelocityGravity(SidewaysVector.x*speed,SidewaysVector.y*-1*speed);
		//cbCollisionObject->SetVelocity(-5,0,0);
		//cbCollisionObject->SetVelocity(SidewaysVector.x*speed,SidewaysVector.y*speed,SidewaysVector.z*speed);
		break;
		}
	case 4:
		{
		cout <<"Right";
		cbCollisionObject->SetVelocityGravity(SidewaysVector.x*-1*speed,SidewaysVector.y*speed);
		//cbCollisionObject->SetVelocity(5,0,0);
		//cbCollisionObject->SetVelocity(SidewaysVector.x*-1*speed,SidewaysVector.y*speed,SidewaysVector.z*-1*speed);
		break;
		}
	default: cout<<"No Direction";
		break;
	}

}

void PlayerObject::SetVectors()
{
	SidewaysVector.x = LookAtLocation.x - Position.x;  
	SidewaysVector.y = LookAtLocation.z - Position.z;  
	glm::vec2 swap;
	swap.x = SidewaysVector.y;
	swap.y = SidewaysVector.x;
	SidewaysVector = swap;
	float magnitude = sqrt(SidewaysVector.x*SidewaysVector.x+SidewaysVector.y*SidewaysVector.y);
	SidewaysVector.x = SidewaysVector.x/magnitude;
	SidewaysVector.y = SidewaysVector.y/magnitude;//SidewaysVector.y/magnitude;
	
	ForwardVector.x = LookAtLocation.x - Position.x;
	ForwardVector.y = LookAtLocation.z - Position.z;
	magnitude = sqrt(ForwardVector.x*ForwardVector.x+ForwardVector.y*ForwardVector.y);
	ForwardVector.x = ForwardVector.x/magnitude;
	ForwardVector.y = ForwardVector.y/magnitude;

}
void PlayerObject::RotateRight()
{
	angle += 0.1f;
	lx = sin(angle);
	lz = -cos(angle);
}

void PlayerObject::RotateLeft()
{
	angle -= 0.1f;
	lx = sin(angle);
	lz = -cos(angle);
}

glm::vec3 PlayerObject::GetLookAt()
{
	return glm::vec3(Position.x+lx,Position.y,Position.z+lz);
}

glm::vec3 PlayerObject::GetUpVector()
{
	return UpVector;
}

void PlayerObject::Update()
{
	cbCollisionObject->Update();
	Position = cbCollisionObject->GetPosition();
	LookAtLocation = glm::vec3(Position.x+lx,Position.y,Position.z+lz);
	UpVector = glm::vec3(0,1,0);
	SetVectors();

}