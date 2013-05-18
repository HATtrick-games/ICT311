#include "StdAfx.h"
#include "Game.h"

boost::scoped_ptr<Game> Game::pSingleton(NULL);

Game::Game()
{
	Player = new PlayerObject(glm::vec3(0,3,0),glm::vec3(0,3,-1),glm::vec3(0,1,0));
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
	(*pGraphicsEng)->RenderTerrain("heightmap.bmp",1);
}

void Game::Update()
{
	CollisionWorldSingleton::Instance()->StepWorld();
	Player->Update();
	
	//cout<<Player->GetPosition().x<<Player->GetPosition().y<<Player->GetPosition().z<<"\n";
	//cout<<"Updating \n";
}


void Game::Input()
{
	if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,-0.1));
		Player->MovePlayer(1);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,0.1));
		Player->MovePlayer(2);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(0.1,0,0));
		Player->MovePlayer(4);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))
	{
		(*pGraphicsEng)->MoveCamera(true, glm::vec3(-0.1,0,0));
		Player->MovePlayer(3);
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