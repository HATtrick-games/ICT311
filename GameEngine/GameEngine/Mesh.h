#pragma once

#include "IAsset.h"
#include "Texture.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>

#include <GL/freeglut.h>

#include <vector>

struct Vertex
{
	glm::vec3 m_pos;
	glm::vec2 m_tex;
	glm::vec3 m_normal;

	Vertex() {}

	Vertex(const glm::vec3& pos, const glm::vec2& tex, const glm::vec3& normal) :
	m_pos(pos), m_tex(tex), m_normal(normal)
	{}
};

struct MeshEntry
{
	MeshEntry();

	~MeshEntry();

	void Init(const std::vector<Vertex>& vertices, 
		const std::vector<unsigned int>& indicies);

	std::vector<Vertex> vVertices;
	std::vector<unsigned int> vIndicies;
	unsigned int numIndicies;
	unsigned int materialIndex;
};

class Mesh:
	public IAsset
{
public:
	Mesh(void);
	~Mesh(void);

	virtual void Load();

	std::vector<MeshEntry>* GetMeshEntries();
	std::vector<Texture*>* GetTextures();

private:
	bool InitFromScene(const aiScene* pScene, const std::string& filePath);
	void InitMesh(unsigned int Index, const aiMesh* paiMesh);
	bool InitMaterials(const aiScene* pScene, const std::string& filePath);
	void Clear();
	
	std::vector<Texture*> m_textures;
	std::vector<MeshEntry> m_entries;
};