#include "StdAfx.h"
#include "Mesh.h"


Mesh::Mesh(void)
{
	MinX = std::numeric_limits<float>::max();
	MinY = std::numeric_limits<float>::max();
	MinZ = std::numeric_limits<float>::max();
	MaxX = std::numeric_limits<float>::min();
	MaxY = std::numeric_limits<float>::min();
	MaxZ = std::numeric_limits<float>::min();
}


Mesh::~Mesh(void)
{
}

void Mesh::Load()
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(sFilepath.c_str(), 
		aiProcessPreset_TargetRealtime_Fast);

	if(scene)
	{
		InitMesh(scene, sFilepath);
	}
	else
	{
		std::cout << "Cannot find " << sFilepath << " " << importer.GetErrorString() << std::endl;
	}
}

void Mesh::InitMesh(const aiScene* pScene, const std::string& sFilepath)
{
	
	assert(pScene->mNumMeshes | !"Only one mesh per scene is allowed.");

	const aiMesh* Mesh = pScene->mMeshes[0];

	VertexArray = new float[Mesh->mNumFaces*3*3];
	NormalArray = new float[Mesh->mNumFaces*3*3];
	UVArray = new float[Mesh->mNumFaces*3*2];

	for(unsigned int i=0;i<Mesh->mNumFaces;i++)
	{
		const aiFace& face = Mesh->mFaces[i];
 
		//foreach index
		for(int j=0;j<3;j++)//assume all faces are triangulated
		{
			aiVector3D uv = Mesh->mTextureCoords[0][face.mIndices[j]];
			memcpy(UVArray,&uv,sizeof(float)*2);
			UVArray+=2;
 
			aiVector3D normal = Mesh->mNormals[face.mIndices[j]];
			memcpy(NormalArray,&normal,sizeof(float)*3);
			NormalArray+=3;
 
			aiVector3D pos = Mesh->mVertices[face.mIndices[j]];
			memcpy(VertexArray,&pos,sizeof(float)*3);
			VertexArray+=3;

			
			//std::cout << VertexArray[j*3] << " " << VertexArray[j*3+1] <<  std::endl;
	//std::getchar();
		}
	}


 
	UVArray-=Mesh->mNumFaces*3*2;
	NormalArray-=Mesh->mNumFaces*3*3;
	VertexArray-=Mesh->mNumFaces*3*3;

	numTextures = Mesh->mNumFaces*3*2;
	numVert = Mesh->mNumFaces*3*3;

		
	for(int i =0; i < Mesh->mNumFaces*3*3; i++)
	{
		MaxX = CommonFunctions::GetMaximum(MaxX, VertexArray[i]);
		MinX = CommonFunctions::GetMinimum(MinX, VertexArray[i]);
		i++;
		MaxY = CommonFunctions::GetMaximum(MaxY, VertexArray[i]);
		MinY = CommonFunctions::GetMinimum(MinY, VertexArray[i]);
		i++;
		MaxZ = CommonFunctions::GetMaximum(MaxZ, VertexArray[i]); 
		MinZ = CommonFunctions::GetMinimum(MinZ, VertexArray[i]);	
	}

	aiString path;
	aiReturn texFound = pScene->mMaterials[1]->GetTexture(aiTextureType_DIFFUSE, 0, &path);
	TexPath = path.data;
	
}

std::string Mesh::GetTexPath()
{
	return TexPath;
}

int Mesh::GetNumTextures()
{
	return numTextures;
}

int Mesh::GetNumVert()
{
	return numVert;
}
float * Mesh::GetVertexArray()
{
	return VertexArray;
}
float * Mesh::GetUVArray()
{
	return UVArray;
}

float Mesh::GetMaxX()
{
	return MaxX;
}
float Mesh::GetMinX()
{
	return MinX;
}
float Mesh::GetMaxY()
{
	return MaxY;
}
float Mesh::GetMinY()
{
	return MinY;
}
float Mesh::GetMaxZ()
{
	return MaxZ;
}
float Mesh::GetMinZ()
{
	return MinZ;
}