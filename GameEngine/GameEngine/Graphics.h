#pragma once

#include <string>

class Graphics abstract
{
public:

private:

	virtual void Init() = 0;
	virtual void DrawModel(std::string Path) = 0;
	virtual void Reshape(int width, int height) = 0;
};
