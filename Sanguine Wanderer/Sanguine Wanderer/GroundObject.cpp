#include "stdafx.h"
#include "GroundObject.h"
#include <Windows.h>
#include "wtypes.h"
#include <iostream>

void GroundObject::InitialiseCollisionBody(glm::vec3 pos)
{
	cout<<"CALLLLLLLLLLLLLLLLLLLLED";
	cbCollisionObject = new CollisionBody(Position, 3);
}