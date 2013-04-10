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
	//(*AssetManager::GetInstance())->AddAsset("towerstone.bmp", "TEXTURE");
	(*AssetManager::GetInstance())->AddAsset("BoxTest.obj", "MESH");
	(*AssetManager::GetInstance())->AddAsset("./data/Cube.obj", "MESH");
	boxMesh = (Mesh*)((*AssetManager::GetInstance())->GetAsset("BoxTest.obj"));
	boxMesh1 = (Mesh*)((*AssetManager::GetInstance())->GetAsset("./data/Cube.obj"));
	testObject = new GameObject();
	glm::vec3 newPos;
	newPos.x = 0.5;
	newPos.y = 0.1;
	newPos.z = -1;
	testObject->SetPosition(newPos);
	testObject1 = new GameObject();
	newPos.x = -1;
	newPos.y = 0;
	newPos.z = -1;
	testObject1->SetPosition(newPos);
	Camera = new PlayerObject();
	Camera->SetPlayerCameraPosition(glm::vec3(0,0,0));
	Camera->SetPlayerCameraLookAt(glm::vec3(0,0,-10));
	(*Camera::GetInstance())->StorePlayerObj((*PlayerObject::GetInstance()).get());
	(*ScriptingEngine::GetInstance())->LoadResources();
}

void Game::UnloadResources()
{
	(*AssetManager::GetInstance())->RemoveAllAssets();
}

void Game::Update(float time)
{
	//std::cout << "[C++] Updating" << std::endl;
	CollisionWorldSingleton::Instance()->StepWorld();
	(*ScriptingEngine::GetInstance())->Update(time);

	(*PlayerObject::GetInstance())->Update();
}

void Game::Draw()
{
	//std::cout << "Drawing" << std::endl;
	//(*OpenGL::GetInstance())->RenderModel(boxMesh, testObject, 0);
	//(*OpenGL::GetInstance())->RenderModel(boxMesh1, testObject1, 1);
	

	/*for(objectMapIterator it = mGameObjects.begin(); it != mGameObjects.end(); it++)
	{
		// Iterate through game objects map drawing all the objects
		// i.e(*OpenGL::GetInstance())->RenderModel((Mesh*)(*AssetManager::GetInstance())->GetAsset((it->second)->GetAssetFile(), it->second, 1));
	}*/
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