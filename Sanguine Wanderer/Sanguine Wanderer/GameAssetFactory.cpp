#include "StdAfx.h"
#include "GameAssetFactory.h"

IAsset* GameAssetFactory::Create(std::string type)
{
	if(type == "TEXTURE")
	{
		//return new Texture;
	}
	else if(type == "MESH")
	{
		return new Mesh;
	}
	else if(type == "TERRAIN")
	{
		//return new Terrain;
	}

	return NULL;
}