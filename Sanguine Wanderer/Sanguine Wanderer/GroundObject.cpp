#include "stdafx.h"
#include "GroundObject.h"
#include <Windows.h>
#include "wtypes.h"
#include <iostream>

void GroundObject::InitialiseCollisionBody(glm::vec3 pos,float x, float y, float z)
{
	cout<<"CALLLLLLLLLLLLLLLLLLLLED";
	cbCollisionObject = new CollisionBody(pos, x,  y,  z, 0);
}