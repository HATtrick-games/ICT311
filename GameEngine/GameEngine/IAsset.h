#pragma once

#include <string>

class IAsset
{
public:
	IAsset();

	void SetFile(std::string file);
	std::string GetFile();

	int GetIdentifier();

	virtual void Load() = 0;
protected:
	std::string sFilepath;
	int iIdentifier;
private:
	static int iCounter;
};

