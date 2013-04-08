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

	(*Input::GetInstance())->SetInputMethod("OPENGL");

	(*ScriptingEngine::GetInstance())->SetScript("SanguineWanderer.lua");
	(*ScriptingEngine::GetInstance())->Initialise();

	LoadResources();
	glutMainLoop();	
}

void Game::LoadResources()
{
	(*AssetManager::GetInstance())->AddAsset("heightmap.bmp", "TEXTURE");
	(*AssetManager::GetInstance())->AddAsset("BoxTest.obj", "MESH");
	boxMesh = (Mesh*)((*AssetManager::GetInstance())->GetAsset("BoxTest.obj"));
	testObject = new PlayerObject();
	CommonFunctions::Pos newPos;
	newPos.x = 0;
	newPos.y = 0;
	newPos.z = -2;
	testObject->SetPosition(newPos);

	(*ScriptingEngine::GetInstance())->LoadResources();
}

void Game::UnloadResources()
{
	(*AssetManager::GetInstance())->RemoveAllAssets();
}

void Game::Update(float time)
{
	(*ScriptingEngine::GetInstance())->Update(time);
}

void Game::Draw()
{
	(*OpenGL::GetInstance())->RenderModel(boxMesh, testObject, 0);
	std::cout << "Drawing" << std::endl;
}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pGame.get() == NULL)
	{
		pGame.reset(new Game);
	}
	return &pGame;
}

void Game::AddGameObject(std::string id, GameObject* obj)
{
	mGameObjects[id] = obj;
}

void Game::RemoveGameObject(std::string id)
{
	mGameObjects.erase(id);
}