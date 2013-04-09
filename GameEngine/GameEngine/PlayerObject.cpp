#include "PlayerObject.h"

PlayerObject::PlayerObject()
{

}

void PlayerObject::Initialise()
{

}

void PlayerObject::Update()
{

}

void PlayerObject::SetPlayerVelocity(float x, float z)
{
	cbCollisionObject->SetVelocityGravity(x,z);
}