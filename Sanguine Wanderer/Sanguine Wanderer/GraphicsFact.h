#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "OpenGL.h"

class GraphicsFact
{
public:
	GraphicsFact(void);
	~GraphicsFact(void);

	boost::scoped_ptr<Graphics> * CreateEngine(std::string Name);
};

