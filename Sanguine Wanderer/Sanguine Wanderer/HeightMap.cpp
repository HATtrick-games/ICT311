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

	int i = 0;
	Heights = new float[h*w];

	for(int y = 0; y < h; y++)
	{

		for(int x = 0; x < w; x++)
		{
			unsigned char color = bits[i];
			Heights[i] = 10 * ((color / 255.0f) - 0.5f);
			i++;
		}
	}
	std::cout << w;
	int total = ((w-1)*2)*(h-1);
	Map = new float[total*3*3];
	UVW = new float[total*2*3];
	NumberHeights = total*3*3;
	i = 0;
	int k = 0;
	int j = 0;
	for(int z = 0; z < h-1; z++)
	{
		for(int x = 0; x < (w-1); x++)
		{		
			Map[i] = x;
			Map[i+1] = Heights[j];
			Map[i+2] = z;

			UVW[k] = ((float)x/(w-1));
			UVW[k+1] = ((float)z/(w-1));

			Map[i+3] = x+1;
			Map[i+4] = Heights[j+1];
			Map[i+5] = z;

			UVW[k+2] = ((float)(x+1)/(w-1));
			UVW[k+3] = ((float)z/(w-1));

			Map[i+6] = x;
			Map[i+7] = Heights[j+(w-1)];
			Map[i+8] = z+1;

			UVW[k+4] = ((float)x/(w-1));
			UVW[k+5] = ((float)(z+1)/(w-1));

			Map[i+9] = x;
			Map[i+10] = Heights[j+(w-1)];
			Map[i+11] = z+1;

			UVW[k+6] = ((float)x/(w-1));
			UVW[k+7] = ((float)(z+1)/(w-1));

			Map[i+12] = x+1;
			Map[i+13] = Heights[j+1];
			Map[i+14] = z;

			UVW[k+8] = ((float)(x+1)/(w-1));
			UVW[k+9] = ((float)z/(w-1));

			Map[i+15] = x+1;
			Map[i+16] = Heights[j+1+(w-1)];
			Map[i+17] = z+1;

			UVW[k+10] = ((float)(x+1)/(w-1));
			UVW[k+11] = ((float)(z+1)/(w-1));
			
			//std::cout << "x:" << UVW[k] << " z:" << UVW[k+1] << std::endl;

			k+=12;
			//k+=2;
			//k++;
			i+=18;
			j++;

			
		}
		//std::getchar();
	}

	NumberTex = total*2*3;
}

float HeightMap::GetY(int x, int z)
{
	return Heights[(x) +(z*59)];
}

float* HeightMap::GetMap()
{
	return Map;
}

float* HeightMap::GetUVW()
{
	return UVW;
}

int HeightMap::GetNumberTex()
{
	return NumberTex;
}

int HeightMap::GetNumberHeights()
{
	return NumberHeights;
}