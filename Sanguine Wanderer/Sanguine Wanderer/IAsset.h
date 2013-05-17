#pragma once
#include "stdafx.h"

class IAsset
{
public:
	IAsset(void);
	~IAsset(void);

	void SetFile(std::string file);

	std::string GetFile();

	int GetIdentifier();

	virtual void Load() = 0;
protected:
	std::string sFilepath;  //!< The filepath
	int iIdentifier;	//!< Zero-based index of the identifier

private:
	static int iCounter;	//!< Zero-based index of the counter
};

