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

class Mesh:
	public IAsset
{
public:
	Mesh(void);
	~Mesh(void);

	virtual void Load();

	Texture* GetTextures(int index);
	std::vector<glm::vec3>* GetVertices();
	std::vector<glm::vec2>* GetTexCoords();
	std::vector<glm::vec3>* GetNormals();
	std::vector<unsigned int>* GetIndicies();
	unsigned int GetnumIndicies();

	CommonFunctions::Pos GetBoundaries();
private:
	bool InitMesh(const aiScene* pScene, const std::string& sFilepath);
	bool InitMaterials(const aiScene* pScene, const std::string& filePath);
	void Clear();
	
	std::vector<Texture*> m_textures;
	std::vector<glm::vec3> vVertices;
	std::vector<glm::vec2> vTexCoords;
	std::vector<glm::vec3> vNormals;
	//std::vector<Vertex> vVertices;
	std::vector<unsigned int> vIndicies;
	unsigned int * faceArray;
	unsigned int numIndicies;
	unsigned int materialIndex;
};