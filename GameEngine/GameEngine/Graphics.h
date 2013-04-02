#pragma once

#include <string>

class Graphics abstract
{
public:

	virtual void Init() = 0;
	virtual void RenderModel(std::string Path) = 0;
	virtual void Reshape(int width, int height) = 0;
	virtual void Display() = 0;

private:

};
