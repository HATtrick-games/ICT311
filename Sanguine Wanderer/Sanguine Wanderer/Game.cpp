#include "StdAfx.h"
#include "Game.h"

boost::scoped_ptr<Game> Game::pSingleton(NULL);

Game::Game()
{
}

void Game::Init()
{
	GraphicsFact GraphicsFactory;
	pGraphicsEng = GraphicsFactory.CreateEngine("OpenGL");
	(*pGraphicsEng)->Initialise();
	(*Input::GetInstance())->SetInputMethod("OPENGL");

	Test = new Mesh;
	Test->SetFile("./data/housebest.obj");
	Test->Load();
	(*pGraphicsEng)->Start();
	
}

void Game::Display()
{
	//call display stuff
	(*pGraphicsEng)->RenderModel(0, Test);	
}

void Game::Input()
{
	if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,-0.1));
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,0.1));
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0.1,0,0));
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(-0.1,0,0));
	}
}

Game::~Game(void)
{

}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new Game);
	}
	return &pSingleton;
}