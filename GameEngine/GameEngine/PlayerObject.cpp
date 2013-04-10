#include "PlayerObject.h"

boost::scoped_ptr<PlayerObject> PlayerObject::pPlayerObject(NULL);

PlayerObject::PlayerObject()
{
	PlayerCameraPosition.x = 1;
	PlayerCameraPosition.y = 5;
	PlayerCameraPosition.z = 20;
	PlayerCameraLookAt.x = 1;
	PlayerCameraLookAt.y = 0;
	PlayerCameraLookAt.z = -10;
	cbCollisionObject->SetCollisionPos(PlayerCameraPosition.x,PlayerCameraPosition.y,PlayerCameraPosition.z);
}

void PlayerObject::Initialise()
{

}

void PlayerObject::SetPosition(glm::vec3 newPos)
{
	float LastX, LastY, LastZ;
	LastX = PlayerCameraPosition.x;
	LastY = PlayerCameraPosition.y;
	LastZ = PlayerCameraPosition.z;
	
	PlayerCameraPosition = newPos;
	PlayerCameraLookAt.x += (PlayerCameraPosition.x - LastX);
	PlayerCameraLookAt.y += (PlayerCameraPosition.y - LastY);
	PlayerCameraLookAt.z += (PlayerCameraPosition.z - LastZ);

	float fx, fy, fz;
	fx =(newPos.x-stPosition.x);
	fy =(newPos.y-stPosition.y);
	fz =(newPos.z-stPosition.z);
	
	cbCollisionObject->TranslateObject(fx,fy,fz);
	//std::cout<<cbCollisionObject->GetPosition().x<<"\n"<<cbCollisionObject->GetPosition().y<<"\n"<<cbCollisionObject->GetPosition().z<<"\n *********** \n \n";
	stPosition = newPos;
}

void PlayerObject::Update()
{
	float LastX, LastY, LastZ;
	LastX = PlayerCameraPosition.x;
	LastY = PlayerCameraPosition.y;
	LastZ = PlayerCameraPosition.z;
	
	stPosition = cbCollisionObject->GetPosition();
	PlayerCameraPosition = cbCollisionObject->GetPosition();
	
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

boost::scoped_ptr<PlayerObject>* PlayerObject::GetInstance()
{
	if(pPlayerObject.get() == NULL)
	{
		pPlayerObject.reset(new PlayerObject);
	}

	return &pPlayerObject;
}