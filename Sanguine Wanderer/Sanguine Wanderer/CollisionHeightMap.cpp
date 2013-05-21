#include "stdafx.h"
#include "CollisionHeightMap.h"

CollisionHeightMap::CollisionHeightMap(float width, float length, std::vector<float> HeightMapData, float MinHeight, float MaxHeight, float Normal)
{
	//data = HeightMapData;
	//btHeightfieldTerrainShape* heightfield = new btHeightfieldTerrainShape(width,length,&data[0],btScalar(1),btScalar(MinHeight),btScalar(MaxHeight),Normal,PHY_FLOAT,false);
	// btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));
     //   btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,groundMotionState,heightfield,btVector3(0,0,0));
      //  HeightMap = new btRigidBody(groundRigidBodyCI);
		//CollisionWorldSingleton::Instance()->AddRigidBody(HeightMap);
}

void CollisionHeightMap::Scale(float scaleX, float scaleY, float scaleZ)
{
	//HeightMap->getCollisionShape()->setLocalScaling(btVector3(scaleX, scaleY, scaleZ));
}

void CollisionHeightMap::Translate(float translateX, float translateY, float translateZ)
{
	//HeightMap->translate(btVector3(translateX, translateY, translateZ));
}