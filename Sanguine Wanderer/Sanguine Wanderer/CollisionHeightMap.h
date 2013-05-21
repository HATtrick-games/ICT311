/**
 * \file	CollisionHeightMap.h
 *
 * \brief	Declares the collision height map class.
 */

#pragma once
#include "CollisionWorldSingleton.h"
#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <vector>

/**
 * \class	CollisionHeightMap
 *
 * \brief	Collision height map.
 *
 * \author	Arran Ford
 * \date	4/10/2013
 */

class CollisionHeightMap
{
public:

	/**
	 * \fn	CollisionHeightMap::CollisionHeightMap(float width, float length,
	 * 		std::vector<float> HeightMapData, float MinHeight, float MaxHeight, float Normal);
	 *
	 * \brief	Constructor.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	width		 	The width.
	 * \param	length		 	The length.
	 * \param	HeightMapData	Information describing the height map.
	 * \param	MinHeight	 	Height of the minimum.
	 * \param	MaxHeight	 	Height of the maximum.
	 * \param	Normal		 	The normal.
	 */

	CollisionHeightMap(float width, float length, std::vector<float> HeightMapData, float MinHeight, float MaxHeight, float Normal);

	/**
	 * \fn	CollisionHeightMap::~CollisionHeightMap()
	 *
	 * \brief	Destructor.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 */

	~CollisionHeightMap(){};

	/**
	 * \fn	void CollisionHeightMap::Scale(float scaleX, float scaleY, float scaleZ);
	 *
	 * \brief	Scales the height map collision mesh.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	scaleX	The scale x coordinate.
	 * \param	scaleY	The scale y coordinate.
	 * \param	scaleZ	The scale z coordinate.
	 */

	void Scale(float scaleX, float scaleY, float scaleZ);

	/**
	 * \fn	void CollisionHeightMap::Translate(float translateX, float translateY, float translateZ);
	 *
	 * \brief	Translates the height map collision mesh.
	 *
	 * \author	Arran Ford
	 * \date	4/10/2013
	 *
	 * \param	translateX	The translate x coordinate.
	 * \param	translateY	The translate y coordinate.
	 * \param	translateZ	The translate z coordinate.
	 */

	void Translate(float translateX, float translateY, float translateZ);


protected:
private:

	/**
	 * \brief	The height map.
	 */

	//btRigidBody* HeightMap;

	/**
	 * \brief	The data.
	 */

	std::vector<float> data;
};