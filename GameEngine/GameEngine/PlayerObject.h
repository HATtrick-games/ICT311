#pragma once
#include "GameObject.h"
#include "glm\glm.hpp"

#include <boost/scoped_ptr.hpp>


class PlayerObject :public GameObject
{
public:
	PlayerObject();
	~PlayerObject(){};
	void SetPlayerVelocity(float x, float z);
	void SetPlayerCameraPosition(glm::vec3 pos);
	void SetPlayerCameraLookAt(glm::vec3 LookAt);
	glm::vec3 GetPlayerCameraPosition();
	glm::vec3 GetPlayerLookAt();

	virtual void Initialise();
	virtual void Update();

	static boost::scoped_ptr<PlayerObject>* GetInstance();
protected:
private:
	glm::vec3 PlayerCameraPosition;
	glm::vec3 PlayerCameraLookAt;

	static boost::scoped_ptr<PlayerObject> pPlayerObject;
};