#include "PlayerObject.h"

PlayerObject::PlayerObject()
{
	PlayerCameraPosition.x = 1;
	PlayerCameraPosition.y = 0;
	PlayerCameraPosition.z = 0;
	PlayerCameraLookAt.x = 1;
	PlayerCameraLookAt.y = 0;
	PlayerCameraLookAt.z = -10;
	cbCollisionObject->SetCollisionPos(PlayerCameraPosition.x,PlayerCameraPosition.y,PlayerCameraPosition.z);
}

void PlayerObject::Initialise()
{

}

void PlayerObject::Update()
{
	float LastX, LastY, LastZ;
	LastX = PlayerCameraPosition.x;
	LastY = PlayerCameraPosition.y;
	LastZ = PlayerCameraPosition.z;
	PlayerCameraPosition.x = cbCollisionObject->GetPosition().x;
	PlayerCameraPosition.y = cbCollisionObject->GetPosition().y;
	PlayerCameraPosition.z = cbCollisionObject->GetPosition().z;
	PlayerCameraLookAt.x += (PlayerCameraPosition.x - LastX);
	PlayerCameraLookAt.y += (PlayerCameraPosition.y - LastY);
	PlayerCameraLookAt.z += (PlayerCameraPosition.z - LastZ);
}

void PlayerObject::SetPlayerVelocity(float x, float z)
{
	cbCollisionObject->SetVelocityGravity(x,z);
}

void PlayerObject::SetPlayerCameraLookAt(glm::vec3 LookAt)
{
	PlayerCameraLookAt = LookAt;
}

void PlayerObject::SetPlayerCameraPosition(glm::vec3 Pos)
{
	PlayerCameraPosition = Pos;
}

glm::vec3 PlayerObject::GetPlayerCameraPosition()
{
	return PlayerCameraPosition;
}

glm::vec3 PlayerObject::GetPlayerLookAt()
{
	return PlayerCameraLookAt;
}