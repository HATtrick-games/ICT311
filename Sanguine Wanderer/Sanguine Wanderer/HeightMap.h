/**
 * \file	HeightMap.h
 *
 * \brief	Declares the height map class.
 */

#pragma once
#include "stdafx.h"
#include "TextureLoader.h"

/**
 * \class	HeightMap
 *
 * \brief	Height map.
 *
 * \author	Hamish
 * \date	22/05/2013
 */

class HeightMap
{
public:
	HeightMap(void);
	~HeightMap(void);

	/**
	 * \fn	void HeightMap::Load(std::string filename);
	 *
	 * \brief	Loads the given file.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	filename	The filename to load.
	 */

	void Load(std::string filename);

	/**
	 * \fn	void HeightMap::SetHeight(int x, int z, float h);
	 *
	 * \brief	Sets a height.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	x	The x coordinate.
	 * \param	z	The z coordinate.
	 * \param	h	The height.
	 */

	void SetHeight(int x, int z, float h);

	/**
	 * \fn	int HeightMap::GetWidth()
	 *
	 * \brief	Gets the width.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The width.
	 */

	int GetWidth(){return w;};

	/**
	 * \fn	int HeightMap::GetLength()
	 *
	 * \brief	Gets the length.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The length.
	 */

	int GetLength(){return h;};

	/**
	 * \fn	float* HeightMap::GetHeights()
	 *
	 * \brief	Gets the heights.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the heights.
	 */

	float* GetHeights(){return Heights;};

	/**
	 * \fn	float * HeightMap::GetMap();
	 *
	 * \brief	Gets the vertex array.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the vertex array.
	 */

	float * GetMap();

	/**
	 * \fn	float * HeightMap::GetUVW();
	 *
	 * \brief	Gets the uvw array.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the uvw array.
	 */

	float * GetUVW();

	/**
	 * \fn	int HeightMap::GetNumberHeights();
	 *
	 * \brief	Gets number of heights.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The number of heights.
	 */

	int GetNumberHeights();

	/**
	 * \fn	int HeightMap::GetNumberTex();
	 *
	 * \brief	Gets number of uvw.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The number of uvw.
	 */

	int GetNumberTex();

	/**
	 * \fn	float HeightMap::GetY(int x, int z);
	 *
	 * \brief	Get y coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	x	The x coordinate.
	 * \param	z	The z coordinate.
	 *
	 * \return	The y coordinate.
	 */

	float GetY(int x, int z);
private:

	/**
	 * \brief	The heights.
	 */

	float** pHeights;

	/**
	 * \brief	Array of verticies.
	 */

	float* Map;

	/**
	 * \brief	The height array.
	 */

	float * Heights;

	/**
	 * \brief	The uvw array.
	 */

	float * UVW;

	/**
	 * \brief	Number of textures.
	 */

	int NumberTex;

	/**
	 * \brief	The height.
	 */

	int h;

	/**
	 * \brief	The width.
	 */

	int w;

	/**
	 * \brief	Number of heights.
	 */

	int NumberHeights;
};

