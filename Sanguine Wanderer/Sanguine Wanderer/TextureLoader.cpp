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

void TextureLoader::HeightMap(std::string filename)
{
	
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
/*
// load a height map and normal map (computed from the height map) into opengl with freeimage
bool TextureLoader::loadHeightAndNormalMaps(std::string filename, int Index, double zScale) {
    FIBITMAP *bitmap = NULL;
    if (!loadBitmap(filename, bitmap))
        return false;

    // convert to 8-bit greyscale
    FIBITMAP *bitmapGrey = FreeImage_ConvertToGreyscale(bitmap);
    FreeImage_Unload(bitmap);
    if (!bitmapGrey)
        return false;
    bitmap = bitmapGrey;

    // get bits and dimensions
    BYTE *bits = FreeImage_GetBits(bitmap);
    int w = FreeImage_GetWidth(bitmap);
    int h = FreeImage_GetHeight(bitmap);

	for(int i =0; i < w; i++)
	{
		std::cout << bits[i];
	}
    // allocate a normal map
    FIBITMAP *normals = FreeImage_Allocate(w, h, 24);
    if (!normals) { // failed to alloc
        FreeImage_Unload(bitmap); // do or do not there is no try
        return false;
    }

	TextureHandle.push_back(0);
	TexBuffer.push_back(0);
	TexBuffer.push_back(0);

    // upload heightmap to opengl
    glGenTextures(1, &TextureHandle[Index]);
    glBindTexture(GL_TEXTURE_2D, TextureHandle[Index]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, w, h, GL_RED, GL_UNSIGNED_BYTE, (GLvoid*)bits);

    // compute normals
    computeNormalMapFromHeightMap(bitmap, normals, zScale);

    // get bit order
    int order = GL_BGR;
    #if FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_RGB
    order = GL_RGB;
    #endif

    bits = FreeImage_GetBits(normals);

    // upload heightmap to opengl
    glGenTextures(1, &TexBuffer[Index]);
    glBindTexture(GL_TEXTURE_2D, TexBuffer[Index]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0, order, GL_UNSIGNED_BYTE, (GLvoid*)bits);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // forget our copy of the bitmap now that it's stored the card
    FreeImage_Unload(bitmap);
    FreeImage_Unload(normals);

    return true;
}
namespace {
    // helper function for getting pixels from a bitmap
    inline double pix(FIBITMAP* map, int x, int y) {
        unsigned char val;
        FreeImage_GetPixelIndex(map, x, y, &val); // slow because of bounds checks, but who cares?  this is a preprocess.
        return val / 255.0;
    }
}
// called by the height & normal map loader, computes normals from height map
void TextureLoader::computeNormalMapFromHeightMap(FIBITMAP *heights, FIBITMAP *normals, double zScale) {
    RGBQUAD color;
    int w = FreeImage_GetWidth(heights);
    int h = FreeImage_GetHeight(heights);

    // march xPrev,x,xNext triple over range, assuming the texture wraps
    for (int xPrev = w-2, x = w-1, xNext = 0; xNext < w; xPrev=x, x=xNext++) {

        // similarly, march yPrev,y,yNext triple
        for (int yPrev = h-2, y = h-1, yNext = 0; yNext < h; yPrev=y, y=yNext++) {
            // @TODO: Compute the normal from the height map
            // HINT: The pix function may help.
			vec3 tan1 = vec3(2, 0, pix(heights,xNext, y) - pix(heights,xPrev, y));
			vec3 tan2 = vec3(0, 2, pix(heights,x, yNext) - pix(heights,x, yPrev));

			vec3 normal = tan1 ^ tan2;
			normal[2] = normal[2]*zScale;
			normal.normalize();
			//normal now between -1 and 1, need to scale to 0 to 1
			normal = normal + vec3(1,1,1);
			//need to scale to 0 to 255
			normal = normal/2;
			normal *= 255;

            color.rgbRed = BYTE(normal[0]);
            color.rgbGreen = BYTE(normal[1]);
            color.rgbBlue = BYTE(normal[2]);
            FreeImage_SetPixelColor(normals,x,y,&color);
        }
    }
}
/*
FIBITMAP* TextureLoader::LoadBitmapOnly(std::string Path)
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
	return dib;
}*/

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
