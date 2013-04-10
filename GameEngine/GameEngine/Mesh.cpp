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
		InitMesh(scene, sFilepath);
	}
	else
	{
		std::cout << "Cannot find " << sFilepath << " " << importer.GetErrorString() << std::endl;
		//throw std::runtime_error(std::string("Error Parsing: ") + sFilepath +
			//std::string("\n") + importer.GetErrorString());
	}
}

Texture* Mesh::GetTextures(int index)
{
	return m_textures[0];
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

bool Mesh::InitMesh(const aiScene* pScene, const std::string& sFilepath)
{

	assert(pScene->mNumMeshes | !"Only one mesh per scene is allowed.");
	m_textures.resize(pScene->mNumMaterials);

	const aiMesh* Mesh = pScene->mMeshes[0];

	materialIndex = Mesh->mMaterialIndex;

	const aiVector3D zero3D(0.0f, 0.0f, 0.0f);

	for(unsigned int i = 0; i < Mesh->mNumVertices; ++i)
	{
		//std::cout << Mesh->mVertices[i].x <<  " | " << Mesh->mVertices[i].y << " | " << Mesh->mVertices[i].z << std::endl;
		const aiVector3D* pPos = &(Mesh->mVertices[i]);
		const aiVector3D* pNormal = &(Mesh->mNormals[i]);
		const aiVector3D* pTexCoord = Mesh->HasTextureCoords(0) ?
			&(Mesh->mTextureCoords[0][i]) :
			&zero3D;

		vVertices.push_back(glm::vec3(pPos->x,pPos->y,pPos->z));
		vTexCoords.push_back(glm::vec2(pTexCoord->x, pTexCoord->y));
		vNormals.push_back(glm::vec3(pNormal->x, pNormal->y, pNormal->z));

		/*Vertex v(glm::vec3(pPos->x, pPos->y, pPos->z),
			glm::vec2(pTexCoord->x, pTexCoord->y),
			glm::vec3(pNormal->x, pNormal->y, pNormal->z));

		vVertices.push_back(v);*/
	}


	for(unsigned int i = 0; i < Mesh->mNumFaces; ++i)
	{
		const aiFace& face = Mesh->mFaces[i];
		assert(face.mNumIndices == 3);
		vIndicies.push_back(face.mIndices[0]);
		vIndicies.push_back(face.mIndices[1]);
		vIndicies.push_back(face.mIndices[2]);	
	}

	numIndicies = vIndicies.size();
	
	
	//for(int j = 0; j < Mesh->mNumFaces * 3; j++)
	//{
		//std::cout << faceArray[j];
	//std::cout << &vVertices[j] << " | " << vVertices[j].x <<  " | "<< vVertices[j].y <<" | " << vVertices[j].z << j<< std::endl;
	//std::cout << &vVertices[j] << " | " << vVertices[j].y <<  " | "<< j;
	//std::cout << &vVertices[j] << " | " << vVertices[j].z <<  " | "<< j << std::endl;
	//}

	return InitMaterials(pScene, sFilepath);
}

std::vector<glm::vec3>* Mesh::GetVertices()
{
	//std::cout << vVertices[0].x;
	//std::cout << "Test1";
	return &vVertices;
}

std::vector<glm::vec2>* Mesh::GetTexCoords()
{
	return &vTexCoords;
}

std::vector<glm::vec3>* Mesh::GetNormals()
{
	return &vNormals;
}

std::vector<unsigned int>* Mesh::GetIndicies()
{
	return &vIndicies;
}

unsigned int Mesh::GetnumIndicies()
{
	return numIndicies;
}

bool Mesh::InitMaterials(const aiScene* pScene, const std::string& filePath)
{
	std::cout << "Init Materials" << pScene->mNumMaterials << std::endl;

	std::string::size_type slashIndex = filePath.find_last_of("/");
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

			std::cout << pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, 
				NULL, NULL, NULL, NULL) << std::endl;

			if(pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, 
				NULL, NULL, NULL, NULL) == AI_SUCCESS)
			{
				std::string fullPath = dir + "/" + path.data;

				m_textures[i] = new Texture();
				m_textures[i]->SetFile(fullPath);
				m_textures[i]->Load();

				std::cout << m_textures[i]->GetFile() << std::endl;

				if(m_textures[i]->GetData().size() == 0)
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
			m_textures[i] = new Texture();
			m_textures[i]->SetFile("heightmap.bmp");
			m_textures[i]->Load();

			if(m_textures[i]->GetData().size() == 0)
			{
				ret = false;
			}
		}

		std::cout << "Loaded " << m_textures[i]->GetFile() << " into " << m_textures[i]->GetAddress() << std::endl;
	}

	

	return ret;
}

void Mesh::Clear()
{
	for(unsigned int i = 0; i < m_textures.size(); ++i)
	{
		delete m_textures[i];
	}

	vVertices.clear();
	vNormals.clear();
	vTexCoords.clear();
	vIndicies.clear();
}

/*void MeshEntry::Init(const std::vector<Vertex>& vertices, 
	const std::vector<unsigned int>& indicies)
{
	numIndicies = indicies.size();

	vVertices = vertices;
	vIndicies = indicies;

	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numIndicies, &indicies[0], GL_STATIC_DRAW);
}*/

CommonFunctions::Pos Mesh::GetBoundaries()
{
	CommonFunctions::Pos average;
	average.x = 0;
	average.y = 0;
	average.z = 0;

	CommonFunctions::Pos boundary;
	boundary.x = 0;
	boundary.y = 0;
	boundary.z = 0;

	for(int i = 0; i < vVertices.size(); i++)
	{
		average.x += vVertices[i].x;
		average.y += vVertices[i].y;
		average.z += vVertices[i].z;
		
		boundary.x = CommonFunctions::GetMaximum(boundary.x, abs(vVertices[i].x));
	}

	boundary.x -= average.x;
	boundary.y -= average.y;
	boundary.z -= average.z;

	return boundary;
}