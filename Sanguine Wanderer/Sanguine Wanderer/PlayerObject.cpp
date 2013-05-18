#include "stdafx.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject()
{


}

PlayerObject::PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector)
{
	Position = StartingLocation;
	LookAtLocation = StartingLookAt;
	UpVector = StartingUpVector;
	cbCollisionObject = new CollisionBody(Position);
	//CollisionBody* cbCollisionObject;

}

void PlayerObject::StopPlayer(int Direction)
{
	switch (Direction)
	{
	case 1: 
		{
		cout << "Forward";
		cbCollisionObject->SetXVelocity(0);
		break;
		}
	case 2:
		{
		cout <<"Back";
		cbCollisionObject->SetZVelocity(0);
		break;
		}
	default: cout<<"No Direction";
		break;
	}
}

void PlayerObject::MovePlayer(int Direction)
{
	//cbCollisionObject->SetVelocity(2,0,0);

	switch (Direction)
	{
	case 1: 
		{
		cout << "Forward";
		cbCollisionObject->SetVelocity(0,0,-2);
		break;
		}
	case 2:
		{
		cout <<"Back";
		cbCollisionObject->SetVelocity(0,0,2);
		break;
		}
	case 3:
		{
		cout <<"Left";
		cbCollisionObject->SetVelocity(-2,0,0);
		break;
		}
	case 4:
		{
		cout <<"Right";
		cbCollisionObject->SetVelocity(2,0,0);
		break;
		}
	default: cout<<"No Direction";
		break;
	}

}

void PlayerObject::Update()
{
	Position = cbCollisionObject->GetPosition();
}