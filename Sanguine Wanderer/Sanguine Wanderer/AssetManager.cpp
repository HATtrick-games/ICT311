#include "StdAfx.h"
#include "AssetManager.h"

boost::scoped_ptr<AssetManager> AssetManager::pAssetManager(NULL);

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
	if(mGameAssets[filename] == NULL)
	{
		mGameAssets[filename] = GameAssetFactory::Create(type);
		mGameAssets[filename]->SetFile(filename);
		mGameAssets[filename]->Load();
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

boost::scoped_ptr<AssetManager>* AssetManager::GetInstance()
{
	if(pAssetManager.get() == NULL)
	{
		pAssetManager.reset(new AssetManager);
	}

	return &pAssetManager;
}