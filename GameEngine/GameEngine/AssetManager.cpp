#include "AssetManager.h"

AssetManager::AssetManager(void)
{
	mGameAssets.clear();
}

AssetManager::~AssetManager(void)
{
	mGameAssets.clear();
}

bool AssetManager::AddAsset(string filename, string type)
{
	if(mGameAssets[filename] != NULL)
	{
		mGameAssets[filename] = GameAssetFactory::Create(type);
	}

	// Check if the asset was loaded in
	if(mGameAssets[filename] == NULL)
	{
		return false;
	}

	return true;
}

IAsset* AssetManager::GetAsset(string filename)
{
	return mGameAssets[filename];
}

void AssetManager::RemoveAsset(string filename)
{
	mGameAssets.erase(filename);
}

bool AssetManager::RemoveAllAssets()
{
	mGameAssets.clear();
	
	if(mGameAssets.empty())
	{
		return true;
	}
	
	return false;
}