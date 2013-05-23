#include "StdAfx.h"
#include "Game.h"

boost::scoped_ptr<Game> Game::pSingleton(NULL);

Game::Game()
{

	Player = new PlayerObject(glm::vec3(0,10,-100),glm::vec3(0,10,-19),glm::vec3(0,1,0));
	
	plane = new GroundObject();
	plane->InitialiseCollisionBody(glm::vec3(0,1,0), 10000, 1,10000);
	plane1 = new GroundObject();
	plane1->InitialiseCollisionBody(glm::vec3(0,0,320), 100000,100000,1);
	
	plane2 = new GroundObject();
	plane2->InitialiseCollisionBody(glm::vec3(0,0,-130),100000,100000,1);
	plane3 = new GroundObject();
	plane3->InitialiseCollisionBody(glm::vec3(-80,0,0), 1,1000,10000);
	plane4 = new GroundObject();
	plane4->InitialiseCollisionBody(glm::vec3(330,0,0),1,1000,10000); 
}

void Game::Init()
{
	GraphicsFact GraphicsFactory;
	pGraphicsEng = GraphicsFactory.CreateEngine("OpenGL");
	(*pGraphicsEng)->Initialise();
	(*Input::GetInstance())->SetInputMethod("OPENGL");


	/*===== AI INITIALISATION =====*/
	/*
	Enemy1 = new AIObject;
	Enemy2 = new AIObject;

	Enemy1->SetTarget(Player);
	Enemy2->SetTarget(Player);
	Knight->SetTarget(Player);

	(*AIScripting::GetInstance())->LoadScript("luascripts/statemachine.lua");

	luabind::object state = luabind::globals((*AIScripting::GetInstance())->lState);

	Enemy1->GetFSM()->SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
	Enemy1->GetFSM()->ChangeState(luabind::object_cast<luabind::object>(state["state_idle"]));

	Enemy2->GetFSM()->SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
	Enemy2->GetFSM()->ChangeState(luabind::object_cast<luabind::object>(state["state_idle"]));

	Knight->GetFSM()->SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
	Knight->GetFSM()->ChangeState(luabind::object_cast<luabind::object>(state["state_idle"]));

	(*AIObjectManager::GetInstance())->RegisterObject(Knight);
	(*AIObjectManager::GetInstance())->RegisterObject(Enemy1);
	(*AIObjectManager::GetInstance())->RegisterObject(Enemy2);
	*/
	
	InitialiseProps();

	Terrain = new HeightMap;

	Terrain->Load("HeightmapFinal.bmp");

	(*pGraphicsEng)->Start();
}


void Game::Display()
{
	(*pGraphicsEng)->RenderTerrain(Terrain);

	(*pGraphicsEng)->RenderModel(Knight);

	for(i = PropObjects.begin(); i != PropObjects.end(); ++i)
	{
		(*pGraphicsEng)->RenderModel(*i);
	}
}


void Game::Update()
{
	//cout<<"\n PLANE Y +++"<<plane->GetPosition().y;
	
	GroundCollide->Update();
	Input();
	Player->Update(Terrain->GetY(Player->GetPosition().x,Player->GetPosition().z));
	CollisionWorldSingleton::Instance()->StepWorld();
	(*pGraphicsEng)->SetCam(Player->GetPosition());
	(*pGraphicsEng)->SetLook(Player->GetLookAt());
	//Knight->SetPosition(glm::vec3(10, 0, 10));
	Knight->Update();
	(*AIObjectManager::GetInstance())->UpdateAI(1.0/20.0);
	//std::cout << Knight->GetPosition().x << " " << Knight->GetPosition().z << std::endl;
	

}
void Game::MouseMove(int x, int y)
{
	Player->MouseMove(x,y);



}

void Game::Input()
{
	if((!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))) &&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100)))&&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115)))&&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))))
	{
		
		Player->StopPlayer();
	}

	if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(32))
	{
		Player->Jump();
	}

	if(((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))&&((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100)))
	{
		Player->MovePlayer(5);
	}
	else if(((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))&&((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97)))
	{
		Player->MovePlayer(6);
	}
	else if(((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))&&((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100)))
	{
		Player->MovePlayer(7);
	}
	else if(((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))&&((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97)))
	{
		Player->MovePlayer(8);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))
	{
		
		
		Player->MovePlayer(1);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))
	{
		
		Player->MovePlayer(2);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100))
	{
		
		Player->MovePlayer(4);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))
	{
		
		Player->MovePlayer(3);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(101))
	{
		Player->RotateRight();
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(113))
	{
		Player->RotateLeft();
	}
	else
	{
		
		Player->StopPlayer();
	}
}

Game::~Game(void)
{
	delete Enemy1;
	delete Enemy2;
}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new Game);
	}
	return &pSingleton;
}

void Game::InitialiseProps()
{
	Animation* TempAni = new Animation((*pGraphicsEng)->GetGraphics());
	Mesh * TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightDefault.obj");
	TempMesh->Load();
	TempAni->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/Knight2.obj");
	TempMesh->Load();
	TempAni->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightFinal.obj");
	TempMesh->Load();
	TempAni->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/Knight3.obj");
	TempMesh->Load();
	TempAni->AddAnimation(TempMesh, TWalk);
	
	TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightDefault.obj");
	TempMesh->Load();
	TempAni->AddAnimation(TempMesh, TWalk);

	GameObject* Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/Skybox.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(0,-50,0));
	Temp->SetScale(glm::vec3(100,100,100));
	Temp->SetRotation(glm::vec3(0,180,0));
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/housebest.obj");
	Temp->GetMesh()->Load();

	Temp->SetPosition(glm::vec3(10,1,-60));
	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/housebest.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(30,1,-60));
	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/Tower.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(200,0,200));
	Temp->SetScale(glm::vec3(0.5,0.5,0.5));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/housebest.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(-19,0,-60));
	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/RockObj.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(-19,0,-80));

	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/RockObj.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(-19,0,-95));
	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	/*
	Temp = new GameObject;
	Temp->SetMesh(new Mesh);
	Temp->GetMesh()->SetFile("./data/RockObj.obj");
	Temp->GetMesh()->Load();
	Temp->SetPosition(glm::vec3(-19,0,-120));
	Temp->SetScale(glm::vec3(0.15,0.15,0.15));
	Temp->SetRotation(glm::vec3(0,0,0));
	Temp->InitialiseCollisionBody();
	PropObjects.push_back(Temp);
	*/
	Knight = new AIObject;
	Knight->SetAnimations(TempAni);
	Knight->ToggleIsAnimating();
	Knight->SetMesh(new Mesh);
	(Knight->GetMesh())->SetFile("./data/KnightDefault.obj");
	(Knight->GetMesh())->Load();
	Knight->SetPosition(glm::vec3(20,0,-4));
	Knight->SetScale(glm::vec3(0.1,0.1,0.1));
	Knight->SetRotation(glm::vec3(0,0,0));
	Knight->InitialiseCollisionBody();

	Knight->SetVelocity(glm::vec2(1,1));
	PropObjects.push_back(Temp);


		/****PROPS LIST ******/
	/*
	GameObject* Rock1 = new GameObject();
	
	(Rock1->GetMesh())->SetFile("./data/GraniteRocks.obj");
	(Rock1->GetMesh())->Load();
	Rock1->SetPosition(glm::vec3(0,0,-10));
	Rock1->SetScale(glm::vec3(0.15,0.15,0.15));
	Rock1->SetRotation(glm::vec3(0,0,0));
	TestProp->InitialiseCollisionBody();
	Rock1->InitialiseCollisionBody();
	PropObjects.push_back(Rock1);*/
}
