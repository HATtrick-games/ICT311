#pragma once
#include "stdafx.h"

class TextureLoader
{
public:
	TextureLoader(void);
	~TextureLoader(void);
	void Load(std::string Path, int Index);
	GLuint GetTexHandle(int index);
	GLuint GetTexBuffer(int index);
	GLuint GetTextureSampler(int index);

	static boost::scoped_ptr<TextureLoader>* TextureLoader::GetInstance();

	void TextureLoader::CreateTexCoordBuffer(float* texCoords, int size, int index);
private:

	std::vector<GLuint> TexBuffer;
	
	std::vector<GLuint> TextureHandle;
	std::vector<GLuint> TextureSampler;

	static boost::scoped_ptr<TextureLoader> pSingleton;
};

