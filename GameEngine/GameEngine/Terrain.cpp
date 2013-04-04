#include "Terrain.h"


Terrain::Terrain(void)
{
	iWidth = 0;
	iLength = 0;
	fScale = 20.0f;
	bNormalsComputed = false;
}


Terrain::~Terrain(void)
{
	for(unsigned int i = 0; i < iLength; i++)
	{
		delete[] pHeights[i];
	}

	delete[] pHeights;

	for(unsigned int i = 0; i < iLength; i++)
	{
		delete[] vNormals[i];
	}

	delete[] vNormals;
}

void Terrain::Load()
{
	std::cout << "Loading Terrain" << std::endl;
	Texture* heightmap = new Texture();
	heightmap->SetFile(sFilepath);
	heightmap->Load();

	iWidth = heightmap->GetWidth();
	iLength = heightmap->GetHeight();

	pHeights = new float*[iLength];
	for(int i = 0; i < iLength; i++)
	{
		pHeights[i] = new float[iWidth];
	}

	vNormals = new glm::vec3*[iLength];
	for(int i = 0; i < iLength; i++)
	{
		vNormals[i] = new glm::vec3[iWidth];
	}

	for(int y = 0; y < iLength; y++)
	{
		for(int x = 0; x < iWidth; x++)
		{
			unsigned char color = heightmap->GetData()[3 * (y * iWidth + x)];
			float h = fScale * ((color / 255.0f) - 0.5f);
			SetHeight(x, y, h);
		}
	}

	delete heightmap;
	ComputeNormals();
}

unsigned int Terrain::GetWidth()
{
	return iWidth;
}

unsigned int Terrain::GetLength()
{
	return iLength;
}

float Terrain::GetHeight(int x, int z)
{
	return pHeights[z][x];
}

glm::vec3 Terrain::GetNormal(int x, int z)
{
	if(!bNormalsComputed)
	{
		ComputeNormals();
	}

	return vNormals[z][x];
}

void Terrain::SetHeight(int x, int z, float h)
{
	pHeights[z][x] = h;
	bNormalsComputed = false;
}

void Terrain::ComputeNormals()
{
	if(bNormalsComputed)
	{
		return;
	}

	glm::vec3** normals = new glm::vec3*[iLength];
	for(int i = 0; i < iLength; i++)
	{
		normals[i] = new glm::vec3[iWidth];
	}

	for(int z = 0; z < iLength; z++)
	{
		for(int x = 0; x < iWidth; x++)
		{
			glm::vec3 sum(0.0f, 0.0f, 0.0f);

			glm::vec3 out;
			if (z > 0)
			{
				out = glm::vec3(0.0f, pHeights[z - 1][x] - pHeights[z][x], -1.0f);
			}
			glm::vec3 in;
			if (z < iLength - 1) 
			{
				in = glm::vec3(0.0f, pHeights[z + 1][x] - pHeights[z][x], 1.0f);
			}
			glm::vec3 left;
			if (x > 0) 
			{
				left = glm::vec3(-1.0f, pHeights[z][x - 1] - pHeights[z][x], 0.0f);
			}
			glm::vec3 right;
			if (x < iWidth - 1) 
			{
				right = glm::vec3(1.0f, pHeights[z][x + 1] - pHeights[z][x], 0.0f);
			}

			if (x > 0 && z > 0) 
			{
				sum += glm::normalize(glm::cross(out, left));
			}
			if (x > 0 && z < iLength - 1) 
			{
				sum += glm::normalize(glm::cross(left, in));
			}
			if (x < iWidth - 1 && z < iLength - 1)
			{
				sum += glm::normalize(glm::cross(in, right));
			}
			if (x < iWidth - 1 && z > 0) 
			{
				sum += glm::normalize(glm::cross(right, out));
			}

			normals[z][x] = sum;
		}
	}

	// Smooth out the normals
	const float FALLOUT_RATIO = 0.5f;
	for(int z = 0; z < iLength; z++)
	{
		for(int x = 0; x < iWidth; x++)
		{
			glm::vec3 sum = normals[z][x];

			if(x > 0)
			{
				sum += normals[z][x - 1] * FALLOUT_RATIO;
			}
			if(x < iWidth - 1)
			{
				sum += normals[z][x + 1] * FALLOUT_RATIO;
			}
			if(z > 0)
			{
				sum += normals[z - 1][x] * FALLOUT_RATIO;
			}
			if(z < iLength - 1)
			{
				sum += normals[z + 1][x] * FALLOUT_RATIO;
			}

			if(sum.length() == 0)
			{
				sum = glm::vec3(0.0f, 1.0f, 0.0f);
			}

			vNormals[z][x] = sum;
		}
	}

	for(int i = 0; i < iLength; i++)
	{
		delete[] normals[i];
	}
	delete[] normals;

	bNormalsComputed = true;
}