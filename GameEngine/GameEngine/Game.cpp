#include "Game.h"

boost::scoped_ptr<Game> Game::pGame(NULL);

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::Initialise()
{
	GraphicsEngFact graphicsFact;
	pGraphicsEng = graphicsFact.CreateEngine("OpenGL"); // TODO make it so this is read from LUA or INI
	(*pGraphicsEng)->Init();

	pInputEngine->SetInputMethod("OPENGL");

	
	glutMainLoop();
}

void Game::LoadResources()
{

}

void Game::UnloadResources()
{

}

void Game::Update(float time)
{

}

void Game::Draw()
{

}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pGame.get() == NULL)
	{
		pGame.reset(new Game);
	}
	return &pGame;
}