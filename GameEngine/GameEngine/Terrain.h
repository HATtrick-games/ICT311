#pragma once

#include "IAsset.h"
#include "Texture.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

/**
 * \class	Terrain
 *
 * \brief	Terrain height mapping using BMP texture.
 * 			
 * \author	Timothy Veletta
 */
class Terrain :
	public IAsset
{
public:

	/**
	 * \fn	Terrain::Terrain(void);
	 *
	 * \brief	Default constructor.
	 */
	Terrain(void);

	/**
	 * \fn	Terrain::~Terrain(void);
	 *
	 * \brief	Destructor.
	 */
	~Terrain(void);

	/**
	 * \fn	virtual void Terrain::Load();
	 *
	 * \brief	Loads this object.
	 */
	virtual void Load();

	/**
	 * \fn	unsigned int Terrain::GetWidth();
	 *
	 * \brief	Gets the width.
	 *
	 * \return	The width.
	 */
	unsigned int GetWidth();

	/**
	 * \fn	unsigned int Terrain::GetLength();
	 *
	 * \brief	Gets the length.
	 *
	 * \return	The length.
	 */
	unsigned int GetLength();

	/**
	 * \fn	float Terrain::GetHeight(int x, int z);
	 *
	 * \brief	Gets a height.
	 *
	 * \param	x	The x coordinate.
	 * \param	z	The z coordinate.
	 *
	 * \return	The height.
	 */
	float GetHeight(int x, int z);

	/**
	 * \fn	glm::vec3 Terrain::GetNormal(int x, int z);
	 *
	 * \brief	Gets a normal.
	 *
	 * \param	x	The x coordinate.
	 * \param	z	The z coordinate.
	 *
	 * \return	The normal.
	 */
	glm::vec3 GetNormal(int x, int z);

	/**
	 * \fn	std::vector<float> Terrain::GetAllHeights();
	 *
	 * \brief	Gets all heights.
	 *
	 * \return	all heights.
	 */
	std::vector<float> GetAllHeights();

	/**
	 * \fn	void Terrain::ComputeNormals();
	 *
	 * \brief	Calculates the normals.
	 */
	void ComputeNormals();
private:
	unsigned int iWidth;	//!< Zero-based index of the width
	unsigned int iLength;   //!< Zero-based index of the length
	float** pHeights;   //!< The heights
	glm::vec3** vNormals;   //!< The normals
	bool bNormalsComputed;  //!< true if normals computed

	float fScale;   //!< The scale

	void SetHeight(int x, int z, float h);
};
