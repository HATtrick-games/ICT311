#include "IAsset.h"

void IAsset::SetFile(std::string file)
{
	sFilepath = file;
}

std::string IAsset::GetFile()
{
	return sFilepath;
}