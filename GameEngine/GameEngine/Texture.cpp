#include "Texture.h"


Texture::Texture(void)
{
	iDataPos = 0;
	iWidth = 0; iHeight = 0;
	iImageSize = 0;
	cData.clear();
}

Texture::~Texture(void)
{
	cData.clear();
}

void Texture::Load()
{
	std::ifstream input(sFilepath, std::ifstream::binary);

	assert(!input.fail() || !"Could not find file.");

	// Check the first 2 characters of the file
	char buffer[2];
	input.read(buffer, 2);
	assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file.");

	input.ignore(8);
	int dataOffset = readInt(input);

	int headerSize = readInt(input);
	switch(headerSize)
	{
	case 40:
		iWidth = readInt(input);
		iHeight = readInt(input);
		input.ignore(2);
		assert(readShort(input) == 24 || !"Image is not 24 bits per pixel.");
		assert(readShort(input) == 0 || !"Image is compressed.");
		break;
	case 12:
		iWidth = readShort(input);
		iHeight = readShort(input);
		input.ignore(2);
		assert(readShort(input) == 24 || !"Image is not 24 bits per pixel.");
		break;
	case 64:
		assert(!"Cannot load OS/2 V2 bitmaps.");
		break;
	case 108:
		assert(!"Cannot load Windows V4 bitmaps.");
		break;
	case 124:
		assert(!"Cannot load Windows V5 bitmaps.");
		break;
	default:
		assert(!"Unknown bitmap format.");
	}

	// Read the data
	int bytesPerRow = ((iWidth * 3 + 3) / 4) * 4 - (iWidth * 3 % 4);
	int size = bytesPerRow * iHeight;
	char* temp = new char[size];

	input.seekg(dataOffset, std::ios_base::beg);
	input.read(temp, size);

	// Format the data correctly
	cData.resize(iWidth * iHeight * 3);
	std::cout << "Size of cData: " <<  iWidth * iHeight * 3 << std::endl;
	for(int y = 0; y < iHeight; y++)
	{
		for(int x = 0; x < iWidth; x++)
		{
			for(int c = 0; c < 3; c++)
			{
				cData[3 * (iWidth * y + x) + c] = 
					temp[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	delete[] temp;

	std::cout << sFilepath << " texture Address:" << &cData << std::endl;
	std::cout << sFilepath << " texture Address:" << GetAddress() << std::endl;
}

unsigned int Texture::GetDataPos()
{
	return iDataPos;
}

unsigned int Texture::GetWidth()
{
	return iWidth;
}

unsigned int Texture::GetHeight()
{
	return iHeight;
}

unsigned int Texture::GetImageSize()
{
	return iImageSize;
}

std::vector<char> Texture::GetData() const
{
	return cData;
}

int Texture::readInt(std::ifstream& input)
{
	char buffer[4];
	input.read(buffer, 4);
	return (int)(((unsigned char)buffer[3] << 24) |
					((unsigned char)buffer[2] << 16) |
					((unsigned char)buffer[1] << 8) |
					(unsigned char)buffer[0]);
}

short Texture::readShort(std::ifstream& input)
{
	char buffer[2];
	input.read(buffer, 2);
	return (short)(((unsigned char)buffer[1] << 8) |
					(unsigned char)buffer[0]);
}

std::vector<char>* Texture::GetAddress()
{
	return &cData;
}