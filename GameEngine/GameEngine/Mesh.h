#pragma once

#include "IAsset.h"
#include "Texture.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>

#include <vector>
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

	std::vector<Texture*>* GetTextures();
	std::vector<float>* GetVertices();
	std::vector<glm::vec2>* GetTexCoords();
	std::vector<glm::vec3>* GetNormals();
	std::vector<unsigned int>* GetIndicies();
	unsigned int GetnumIndicies();

private:
	bool InitMesh(const aiScene* pScene);
	bool InitMaterials(const aiScene* pScene, const std::string& filePath);
	void Clear();
	
	std::vector<Texture*> m_textures;
	std::vector<float> vVertices;
	std::vector<glm::vec2> vTexCoords;
	std::vector<glm::vec3> vNormals;
	//std::vector<Vertex> vVertices;
	std::vector<unsigned int> vIndicies;
	unsigned int numIndicies;
	unsigned int materialIndex;

};