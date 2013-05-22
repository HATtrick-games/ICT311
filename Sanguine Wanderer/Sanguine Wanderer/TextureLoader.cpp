#include "StdAfx.h"
#include "TextureLoader.h"

boost::scoped_ptr<TextureLoader> TextureLoader::pSingleton(NULL);

TextureLoader::TextureLoader(void)
{
	TextureHandle.resize(20);
	TextureSampler.resize(20);
}

void TextureLoader::Load(std::string Path, int index)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP* dib(0);

	fif = FreeImage_GetFileType(Path.c_str(), 0); // Check the file signature and deduce its format

	if(fif == FIF_UNKNOWN) // If still unknown, try to guess the file format from the file extension
		fif = FreeImage_GetFIFFromFilename(Path.c_str());
	
	if(fif == FIF_UNKNOWN) // If still unkown, return failure
		std::cout << "Error 1";

	if(FreeImage_FIFSupportsReading(fif)) // Check if the plugin has reading capabilities and load the file
		dib = FreeImage_Load(fif, Path.c_str());
	if(!dib)
		std::cout << "Error 2";

	BYTE* bDataPointer = FreeImage_GetBits(dib); // Retrieve the image data
	
	unsigned int iWidth = FreeImage_GetWidth(dib); // Get the image width and height
	unsigned int iHeight = FreeImage_GetHeight(dib);
	unsigned int iBPP = FreeImage_GetBPP(dib);
	

	// If somehow one of these failed (they shouldn't), return failure
	if(bDataPointer == NULL || iWidth == 0 || iHeight == 0)
		std::cout << "Error 3";

	TextureHandle.push_back(0);
	TextureSampler.push_back(0);

	glGenTextures(1, &TextureHandle[index]);
	glBindTexture(GL_TEXTURE_2D, TextureHandle[index]); // Bind the ID texture specified by the 2nd parameter

    // The next commands sets the texture parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); //The minifying function
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bDataPointer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 4);

	glGenerateMipmap(GL_TEXTURE_2D);
}


// load a bitmap with freeimage
bool TextureLoader::loadBitmap(string filename, FIBITMAP* &bitmap) {
    // get the file format
    FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename.c_str(), 0);
    if (format == FIF_UNKNOWN)
        format = FreeImage_GetFIFFromFilename(filename.c_str());
    if (format == FIF_UNKNOWN)
        return false;

    // load the image
    bitmap = FreeImage_Load(format, filename.c_str());
    if (!bitmap)
        return false;

    return true;
}

void TextureLoader::FreeBuffer(int index)
{
	glDeleteBuffers(1, &TextureHandle[index]);
}

GLuint TextureLoader::GetTexHandle(int index)
{
	return TextureHandle[index];
}

GLuint TextureLoader::GetTexBuffer(int index)
{
	return TexBuffer[index];
}

GLuint TextureLoader::GetTextureSampler(int index)
{
	return TextureSampler[index];
}

boost::scoped_ptr<TextureLoader>* TextureLoader::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new TextureLoader);
	}
	return &pSingleton;
}

void TextureLoader::CreateTexCoordBuffer(float* texCoords, int size, int index)
{
	TexBuffer.push_back(0);
	glGenBuffers(1, &TexBuffer[index]);
	glBindBuffer(GL_ARRAY_BUFFER, TexBuffer[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*size, texCoords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

TextureLoader::~TextureLoader(void)
{
}
