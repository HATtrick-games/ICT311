#include "StdAfx.h"
#include "HeightMap.h"


HeightMap::HeightMap(void)
{
	NumberHeights = 0;
}


HeightMap::~HeightMap(void)
{
}

void HeightMap::SetHeight(int x, int z, float h)
{
	pHeights[z][x] = h;
	//bNormalsComputed = false;
}

void HeightMap::Load(std::string filename)
{

	FIBITMAP *bitmap = NULL;
    if (!(*TextureLoader::GetInstance())->loadBitmap(filename, bitmap))
        std::cout << "Error";
	FIBITMAP *bitmapGrey = FreeImage_ConvertToGreyscale(bitmap);
    FreeImage_Unload(bitmap);
    if (!bitmapGrey)
        std::cout << "Error2";
    bitmap = bitmapGrey;

    // get bits and dimensions
    BYTE *bits = FreeImage_GetBits(bitmap);
    w = FreeImage_GetWidth(bitmap);
    h = FreeImage_GetHeight(bitmap);

	pHeights = new float*[h];
	for(int i = 0; i < h; i++)
	{
		pHeights[i] = new float[w];
	}

	vNormals = new glm::vec3*[h];
	for(int i = 0; i < h; i++)
	{
		vNormals[i] = new glm::vec3[w];
	}
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			unsigned char color = bits[3 * (y * w + x)];
			float h = 10 * ((color / 255.0f) - 0.5f);
			NumberHeights++;
			SetHeight(x, y, h);
		}
	}

}

void HeightMap::ComputeFloats()
{
	
	int i = 0;
	Map = new float[h*w];
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			Map[i] = pHeights[y][x];
			std::cout << Map[i];
			i++;
		}
	}
}

float* HeightMap::GetMap()
{
	return Map;
}

int HeightMap::GetNumberHeights()
{
	return NumberHeights;
}