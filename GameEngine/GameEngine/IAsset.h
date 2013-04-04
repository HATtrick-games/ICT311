#pragma once

#include <string>

class IAsset
{
public:
	void SetFile(std::string file);
	std::string GetFile();

	virtual void Load() = 0;
protected:
	std::string sFilepath;
};

