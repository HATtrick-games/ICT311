/***CollisionWorld.cpp**/
#include "CollisionWorldSingleton.h"

CollisionWorldSingleton* CollisionWorldSingleton::Instance()
{
	static CollisionWorldSingleton instance;

	return &instance;
}