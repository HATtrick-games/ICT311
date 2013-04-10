#pragma once

#include "IAsset.h"
#include "Texture.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>

#include "CommonFuncs.h"

#include <vector>
#include <cmath>
#include <assert.h>

/*struct Vertex
{
	glm::vec3 m_pos;
	glm::vec2 m_tex;
	glm::vec3 m_normal;

	Vertex() {}

	Vertex(const glm::vec3& pos, const glm::vec2& tex, const glm::vec3& normal) :
	m_pos(pos), m_tex(tex), m_normal(normal)
	{}
};*/

/**
 * \class	Mesh
 *
 * \brief	Model Mesh loading.
 * 			
 * \author Timothy Veletta, Hamish Carrier
 */
class Mesh:
	public IAsset
{
public:

	/**
	 * \fn	Mesh::Mesh(void);
	 *
	 * \brief	Default constructor.
	 */
	Mesh(void);

	/**
	 * \fn	Mesh::~Mesh(void);
	 *
	 * \brief	Destructor.
	 */
	~Mesh(void);

	/**
	 * \fn	virtual void Mesh::Load();
	 *
	 * \brief	Loads this object.
	 */
	virtual void Load();

	/**
	 * \fn	Texture* Mesh::GetTextures(int index);
	 *
	 * \brief	Gets the textures.
	 *
	 * \param	index	Zero-based index of the.
	 *
	 * \return	null if it fails, else the textures.
	 */
	Texture* GetTextures(int index);

	/**
	 * \fn	std::vector<glm::vec3>* Mesh::GetVertices();
	 *
	 * \brief	Gets the vertices.
	 *
	 * \return	null if it fails, else the vertices.
	 */
	std::vector<glm::vec3>* GetVertices();

	/**
	 * \fn	std::vector<glm::vec2>* Mesh::GetTexCoords();
	 *
	 * \brief	Gets tex coords.
	 *
	 * \return	null if it fails, else the tex coords.
	 */
	std::vector<glm::vec2>* GetTexCoords();

	/**
	 * \fn	std::vector<glm::vec3>* Mesh::GetNormals();
	 *
	 * \brief	Gets the normals.
	 *
	 * \return	null if it fails, else the normals.
	 */
	std::vector<glm::vec3>* GetNormals();

	/**
	 * \fn	std::vector<unsigned int>* Mesh::GetIndicies();
	 *
	 * \brief	Gets the indicies.
	 *
	 * \return	null if it fails, else the indicies.
	 */
	std::vector<unsigned int>* GetIndicies();

	/**
	 * \fn	unsigned int Mesh::GetnumIndicies();
	 *
	 * \brief	Gets the getnum indicies.
	 *
	 * \return	.
	 */
	unsigned int GetnumIndicies();

	/**
	 * \fn	CommonFunctions::Pos Mesh::GetBoundaries();
	 *
	 * \brief	Gets the boundaries.
	 *
	 * \return	The boundaries.
	 */
	CommonFunctions::Pos GetBoundaries();
private:
	bool InitMesh(const aiScene* pScene, const std::string& sFilepath);
	bool InitMaterials(const aiScene* pScene, const std::string& filePath);
	void Clear();
	
	std::vector<Texture*> m_textures;   //!< The textures
	std::vector<glm::vec3> vVertices;   //!< The vertices
	std::vector<glm::vec2> vTexCoords;  //!< The tex coords
	std::vector<glm::vec3> vNormals;	//!< The normals
	//std::vector<Vertex> vVertices;
	std::vector<unsigned int> vIndicies;	//!< The indicies

	/**
	 * \property	unsigned int * faceArray
	 *
	 * \brief	Gets an array of faces.
	 *
	 * \return	An Array of faces.
	 */
	unsigned int * faceArray;
	unsigned int numIndicies;   //!< Number of indicies
	unsigned int materialIndex; //!< Zero-based index of the material
};