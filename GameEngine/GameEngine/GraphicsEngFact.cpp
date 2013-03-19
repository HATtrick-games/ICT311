#include "GraphicsEngFact.h"


GraphicsEngFact::GraphicsEngFact(void)
{
}


GraphicsEngFact::~GraphicsEngFact(void)
{
}

boost::scoped_ptr<Graphics> * GraphicsEngFact::CreateEngine(std::string Name)
{
	if(Name == "OpenGL")
	{
		return OpenGL::GetInstance();
	}
}