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
}
/*
switch (reply)
{
case "three": cout << "3";
    break;
case "two": cout << "2";
    break;
case "one": cout << "1";
    break;
default: cout << "qwerty";
    break;*/

void PlayerObject::MovePlayer(int Direction)
{
	
	switch (Direction)
	{
	case 1: cout << "Forward";
		break;
	case 2: cout <<"Back";
		break;
	case 3: cout <<"Left";
		break;
	case 4: cout <<"Right";
		break;
	default: cout<<"No Direction";
		break;
	}

}