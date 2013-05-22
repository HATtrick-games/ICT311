/**
 * \file	Mesh.h
 *
 * \brief	Declares the mesh class.
 */

#pragma once
#include "stdafx.h"
#include "IAsset.h"
#include "CommonFunctions.h"

/**
 * \class	Mesh
 *
 * \brief	Mesh.
 *
 * \author	Chaokel
 * \date	22/05/2013
 */

class Mesh : public IAsset
{
public:

	Mesh(void);

	/**
	 * \fn	void Mesh::Load();
	 *
	 * \brief	Loads this object.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 */

	void Load();

	/**
	 * \fn	void Mesh::InitMesh(const aiScene* pScene, const std::string& sFilepath);
	 *
	 * \brief	Initialises the mesh.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \param	pScene   	The scene.
	 * \param	sFilepath	The filepath.
	 */

	void InitMesh(const aiScene* pScene, const std::string& sFilepath);

	/**
	 * \fn	int Mesh::GetNumTextures();
	 *
	 * \brief	Gets number textures.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The number textures.
	 */

	int GetNumTextures();

	/**
	 * \fn	int Mesh::GetNumVert();
	 *
	 * \brief	Gets number vertical.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The number vertical.
	 */

	int GetNumVert();

	/**
	 * \fn	float * Mesh::GetVertexArray();
	 *
	 * \brief	Gets vertex array.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the vertex array.
	 */

	float * GetVertexArray();

	/**
	 * \fn	float * Mesh::GetUVArray();
	 *
	 * \brief	Gets uv array.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	null if it fails, else the uv array.
	 */

	float * GetUVArray();

	/**
	 * \fn	float Mesh::GetMaxX();
	 *
	 * \brief	Gets maximum x coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The maximum x coordinate.
	 */

	float GetMaxX();

	/**
	 * \fn	float Mesh::GetMaxY();
	 *
	 * \brief	Gets maximum y coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The maximum y coordinate.
	 */

	float GetMaxY();

	/**
	 * \fn	float Mesh::GetMaxZ();
	 *
	 * \brief	Gets maximum z coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The maximum z coordinate.
	 */

	float GetMaxZ();

	/**
	 * \fn	float Mesh::GetMinX();
	 *
	 * \brief	Gets minimum x coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The minimum x coordinate.
	 */

	float GetMinX();

	/**
	 * \fn	float Mesh::GetMinY();
	 *
	 * \brief	Gets minimum y coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The minimum y coordinate.
	 */

	float GetMinY();

	/**
	 * \fn	float Mesh::GetMinZ();
	 *
	 * \brief	Gets minimum z coordinate.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The minimum z coordinate.
	 */

	float GetMinZ();

	/**
	 * \fn	std::string Mesh::GetTexPath();
	 *
	 * \brief	Gets tex path.
	 *
	 * \author	Chaokel
	 * \date	22/05/2013
	 *
	 * \return	The tex path.
	 */

	std::string GetTexPath();

	~Mesh(void);
private:

	/**
	 * \brief	Array of vertices.
	 */

	float * VertexArray;

	/**
	 * \brief	Array of normals.
	 */

	float * NormalArray;

	/**
	 * \brief	Array of uvs.
	 */

	float * UVArray;

	/**
	 * \brief	Number of triangles.
	 */

	int numTriangles;

	/**
	 * \brief	Number of verticals.
	 */

	int numVert;

	/**
	 * \brief	Number of textures.
	 */

	int numTextures;

	/**
	 * \brief	The maximum x coordinate.
	 */

	float MaxX;

	/**
	 * \brief	The maximum y coordinate.
	 */

	float MaxY;

	/**
	 * \brief	The maximum z coordinate.
	 */

	float MaxZ;

	/**
	 * \brief	The minimum x coordinate.
	 */

	float MinX;

	/**
	 * \brief	The minimum y coordinate.
	 */

	float MinY;

	/**
	 * \brief	The minimum z coordinate.
	 */

	float MinZ;

	/**
	 * \brief	Full pathname of the tex file.
	 */

	std::string TexPath;
};

