#include "Engine.h"


Engine::Engine(void)
{

}


Engine::~Engine(void)
{
}

void Engine::Initialise()
{
	// Create 
	GraphicsEngFact graphicsFact;
	pGraphicsEng = graphicsFact.CreateEngine("OpenGL"); // TODO make it so this is read from LUA or INI
	(*pGraphicsEng)->Init();
}

void Engine::Update(float time)
{

}

void Engine::Draw(float time)
{

}

void Engine::Run()
{

}
