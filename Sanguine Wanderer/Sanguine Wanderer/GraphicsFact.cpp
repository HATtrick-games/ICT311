#include "StdAfx.h"
#include "GraphicsFact.h"


GraphicsFact::GraphicsFact(void)
{
}

GraphicsFact::~GraphicsFact(void)
{
}

boost::scoped_ptr<Graphics> * GraphicsFact::CreateEngine(std::string Name)
{
	if(Name == "OpenGL")
	{
		return OpenGL::GetInstance();
	}
	else
	{
		return 0;
	}
}