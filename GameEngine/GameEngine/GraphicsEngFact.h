#pragma once

#include "Graphics.h"
#include "OpenGL.h"

class GraphicsEngFact
{
public:
	GraphicsEngFact(void);
	~GraphicsEngFact(void);

	boost::scoped_ptr<Graphics> * CreateEngine(std::string Name);
};

