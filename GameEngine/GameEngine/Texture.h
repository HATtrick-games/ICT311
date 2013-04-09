#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "IAsset.h"

class Texture:
	public IAsset
{
public:
	Texture(void);
	~Texture(void);

	Texture(const Texture&);
	Texture& operator=(const Texture&);

	virtual void Load();

	unsigned int GetDataPos();
	unsigned int GetWidth();
	unsigned int GetHeight();
	unsigned int GetImageSize();
	std::vector<char> GetData() const;
	std::vector<char>* GetAddress();
private:
	// Data read from the header
	unsigned int iDataPos;
	unsigned int iWidth, iHeight;
	unsigned int iImageSize;
	// RGB Data
	std::vector<char> cData;

	int readInt(std::ifstream& input);
	short readShort(std::ifstream& input);
};

