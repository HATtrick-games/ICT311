#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <string>

class Graphics abstract
{
public:

private:

	virtual void Init() = 0;
	virtual void DrawModel(std::string Path) = 0;
}

#endif