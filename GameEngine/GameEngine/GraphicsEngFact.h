#pragma once

#include "Graphics.h"
#include "OpenGL.h"

class GraphicsEngFact
{
public:
	GraphicsEngFact(void);
	~GraphicsEngFact(void);

	Graphics * CreateEngine(std::string Name);
};

