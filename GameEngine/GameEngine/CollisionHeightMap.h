#pragma once
#include "CollisionWorldSingleton.h"
#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <vector>

class CollisionHeightMap
{
public:
	CollisionHeightMap(float width, float length, std::vector<float> HeightMapData, float MinHeight, float MaxHeight, float Normal);
	~CollisionHeightMap(){};
	void Scale(float scaleX, float scaleY, float scaleZ);
	void Translate(float translateX, float translateY, float translateZ);


protected:
private:
	btRigidBody* HeightMap;
	std::vector<float> data;
};