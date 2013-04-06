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

	LoadResources();
}

void Game::LoadResources()
{
	(*AssetManager::GetInstance())->AddAsset("boxbox.obj", "MESH");

	testObject = new PlayerObject();
}

void Game::UnloadResources()
{
	(*AssetManager::GetInstance())->RemoveAllAssets();
}

void Game::Update(float time)
{

}

void Game::Draw()
{
	Mesh* boxMesh = (Mesh*)((*AssetManager::GetInstance())->GetAsset("boxbox.obj"));
}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pGame.get() == NULL)
	{
		pGame.reset(new Game);
	}
	return &pGame;
}