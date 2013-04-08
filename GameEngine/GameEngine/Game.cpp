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

	LoadResources();
	glutMainLoop();

	
}

void Game::LoadResources()
{

	(*AssetManager::GetInstance())->AddAsset("BoxTest.obj", "MESH");
	boxMesh = (Mesh*)((*AssetManager::GetInstance())->GetAsset("BoxTest.obj"));
	testObject = new PlayerObject();
	CommonFunctions::Pos newPos;
	newPos.x = 0;
	newPos.y = 0;
	newPos.z = -2;
	testObject->SetstPosition(newPos);
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
	(*OpenGL::GetInstance())->RenderModel(boxMesh, testObject, 0);
}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pGame.get() == NULL)
	{
		pGame.reset(new Game);
	}
	return &pGame;
}