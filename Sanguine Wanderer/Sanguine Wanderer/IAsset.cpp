#include "StdAfx.h"
#include "IAsset.h"

int IAsset::iCounter = 1;

IAsset::IAsset()
{
	iIdentifier = iCounter;
	iCounter++;
}

void IAsset::SetFile(std::string file)
{
	sFilepath = file;
}

std::string IAsset::GetFile()
{
	return sFilepath;
}

int IAsset::GetIdentifier()
{
	return iIdentifier;
}

IAsset::~IAsset(void)
{
}
