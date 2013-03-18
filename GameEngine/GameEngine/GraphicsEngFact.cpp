#include "GraphicsEngFact.h"


GraphicsEngFact::GraphicsEngFact(void)
{
}


GraphicsEngFact::~GraphicsEngFact(void)
{
}

Graphics * GraphicsEngFact::CreateEngine(std::string Name)
{
	if(Name == "OpenGL")
	{
		return OpenGL::GetInstance();
	}
}