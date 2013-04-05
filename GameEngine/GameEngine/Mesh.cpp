#include "Mesh.h"


Mesh::Mesh(void)
{
}


Mesh::~Mesh(void)
{
	Clear();
}

void Mesh::Load()
{
	Clear();

	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(sFilepath.c_str(), 
		aiProcess_Triangulate | aiProcess_GenSmoothNormals | 
		aiProcess_FlipUVs);

	if(scene)
	{
		InitFromScene(scene, sFilepath);
	}
	else
	{
		throw std::runtime_error(std::string("Error Parsing: ") + sFilepath +
			std::string("\n") + importer.GetErrorString());
	}
}

std::vector<MeshEntry>* Mesh::GetMeshEntries()
{
	return &m_entries;
}

std::vector<Texture*>* Mesh::GetTextures()
{
	return &m_textures;
}

/*
void Mesh::Render()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	for(unsigned int i = 0; i < m_entries.size(); ++i)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_entries[i].VB);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_entries[i].IB);

		const unsigned int materialIndex = m_entries[i].materialIndex;

		if(materialIndex < m_textures.size() && m_textures[materialIndex])
		{
			m_textures[materialIndex]->Bind(GL_TEXTURE0);
		}

		glDrawElements(GL_TRIANGLES, m_entries[i].numIndicies, GL_UNSIGNED_INT, 0);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}*/

bool Mesh::InitFromScene(const aiScene* pScene, const std::string& filePath)
{
	m_entries.resize(pScene->mNumMeshes);
	m_textures.resize(pScene->mNumMaterials);

	for(unsigned int i = 0; i < m_entries.size(); ++i)
	{
		const aiMesh* paiMesh = pScene->mMeshes[i];
		InitMesh(i, paiMesh);
	}

	return InitMaterials(pScene, filePath);
}

void Mesh::InitMesh(unsigned int index, const aiMesh* paiMesh)
{
	m_entries[index].materialIndex = paiMesh->mMaterialIndex;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indicies;

	const aiVector3D zero3D(0.0f, 0.0f, 0.0f);

	for(unsigned int i = 0; i < paiMesh->mNumVertices; ++i)
	{
		const aiVector3D* pPos = &(paiMesh->mVertices[i]);
		const aiVector3D* pNormal = &(paiMesh->mNormals[i]);
		const aiVector3D* pTexCoord = paiMesh->HasTextureCoords(0) ?
			&(paiMesh->mTextureCoords[0][i]) :
		&zero3D;
		Vertex v(glm::vec3(pPos->x, pPos->y, pPos->z),
			glm::vec2(pTexCoord->x, pTexCoord->y),
			glm::vec3(pNormal->x, pNormal->y, pNormal->z));

		vertices.push_back(v);
	}

	for(unsigned int i = 0; i < paiMesh->mNumFaces; ++i)
	{
		const aiFace& face = paiMesh->mFaces[i];
		assert(face.mNumIndices == 3);
		indicies.push_back(face.mIndices[0]);
		indicies.push_back(face.mIndices[1]);
		indicies.push_back(face.mIndices[2]);
	}

	m_entries[index].Init(vertices, indicies);
}

bool Mesh::InitMaterials(const aiScene* pScene, const std::string& filePath)
{
	/*std::string::size_type slashIndex = filePath.find_last_of("/");
	std::string dir;

	if(slashIndex == std::string::npos)
	{
		dir = ".";
	}
	else if(slashIndex == 0)
	{
		dir = "/";
	}
	else
	{
		dir = filePath.substr(0, slashIndex);
	}

	bool ret = true;

	for(unsigned int i = 0; i < pScene->mNumMaterials; ++i)
	{
		const aiMaterial* pMaterial = pScene->mMaterials[i];

		m_textures[i] = NULL;

		if(pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
		{
			aiString path;

			if(pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, 
				NULL, NULL, NULL, NULL) == AI_SUCCESS)
			{
				std::string fullPath = dir + "/" + path.data;

				m_textures[i] = new Texture(GL_TEXTURE_2D, fullPath.c_str());

				if(!m_textures[i]->Load())
				{
					throw std::runtime_error(
						std::string("Error loading texture: ") + fullPath);
					delete m_textures[i];
					m_textures[i] = NULL;
					ret = false;
				}
				else
				{
					// TODO remove or change to only debug
					printf("Loaded texture: %s", fullPath.c_str());
				}
			}
		}

		if(!m_textures[i])
		{
			m_textures[i] = new Texture(GL_TEXTURE_2D, "white.png");

			ret = m_textures[i]->Load();
		}
	}

	return ret;
	*/
	return false;
}

void Mesh::Clear()
{
	for(unsigned int i = 0; i < m_textures.size(); ++i)
	{
		delete m_textures[i];
	}
}

MeshEntry::MeshEntry()
{
	numIndicies = 0;
	materialIndex = 0;
}

MeshEntry::~MeshEntry()
{
}

void MeshEntry::Init(const std::vector<Vertex>& vertices, 
	const std::vector<unsigned int>& indicies)
{
	numIndicies = indicies.size();

	vVertices = vertices;
	vIndicies = indicies;

	/*glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numIndicies, &indicies[0], GL_STATIC_DRAW);*/
}