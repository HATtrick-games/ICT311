#include "StdAfx.h"
#include "Game.h"

boost::scoped_ptr<Game> Game::pSingleton(NULL);

Game::Game()
{
	Player = new PlayerObject(glm::vec3(0,10,0),glm::vec3(0,3,-1),glm::vec3(0,1,0));
	//Obj = new GameObject();
	//Obj->InitialiseCollisionBody(glm::vec3(0,3,-50));
	//plane = new GroundObject();
	//plane->InitialiseCollisionBody(glm::vec3(0,10,0));
}

void Game::Init()
{
	GraphicsFact GraphicsFactory;
	pGraphicsEng = GraphicsFactory.CreateEngine("OpenGL");
	(*pGraphicsEng)->Initialise();
	(*Input::GetInstance())->SetInputMethod("OPENGL");

	Temp = new Animation((*pGraphicsEng)->GetGraphics());
	Mesh * TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightDefault.obj");
	TempMesh->Load();
	Temp->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/Knight2.obj");
	TempMesh->Load();
	Temp->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightFinal.obj");
	TempMesh->Load();
	Temp->AddAnimation(TempMesh, TWalk);

	TempMesh = new Mesh;
	TempMesh->SetFile("./data/Knight3.obj");
	TempMesh->Load();
	Temp->AddAnimation(TempMesh, TWalk);
	
	TempMesh = new Mesh;
	TempMesh->SetFile("./data/KnightDefault.obj");
	TempMesh->Load();
	Temp->AddAnimation(TempMesh, TWalk);

	Skybox = new GameObject;
	TestProp = new GameObject;
	Knight = new GameObject;
	Rock2 = new GameObject;


	/****PROPS LIST ******/

	/*GameObject* Rock1 = new GameObject();
	

	Rock1->SetMesh(new Mesh);
	(Rock1->GetMesh())->SetFile("./data/GraniteRocks.obj");
	(Rock1->GetMesh())->Load();
	Rock1->SetPosition(glm::vec3(0,0,-10));
	Rock1->SetScale(glm::vec3(0.15,0.15,0.15));
	Rock1->SetRotation(glm::vec3(0,0,0));
	
	Rock1->InitialiseCollisionBody();
	PropObjects.push_back(Rock1);*/
	
	



	



	/*********END PROPS LIST ******/

	Skybox->SetMesh(new Mesh);
	(Skybox->GetMesh())->SetFile("./data/Skybox.obj");
	(Skybox->GetMesh())->Load();
	Skybox->SetPosition(glm::vec3(0,-50,0));
	Skybox->SetScale(glm::vec3(10,10,10));
	Skybox->SetRotation(glm::vec3(0,0,0));

	TestProp->SetMesh(new Mesh);
	(TestProp->GetMesh())->SetFile("./data/housebest.obj");
	(TestProp->GetMesh())->Load();
	TestProp->SetPosition(glm::vec3(0,0,-25));
	TestProp->SetScale(glm::vec3(0.15,0.15,0.15));
	TestProp->SetRotation(glm::vec3(0,180,0));

	Knight->SetAnimations(Temp);
	Knight->ToggleIsAnimating();
	Knight->SetMesh(new Mesh);
	(Knight->GetMesh())->SetFile("./data/KnightDefault.obj");
	(Knight->GetMesh())->Load();
	Knight->SetPosition(glm::vec3(0,0,-4));
	Knight->SetScale(glm::vec3(0.1,0.1,0.1));
	Knight->SetRotation(glm::vec3(0,0,0));


	//TestProp->InitialiseCollisionBody();
	//Skybox->InitialiseCollisionBody();


	Terrain = new HeightMap;
	Terrain->Load("heightmap.bmp");
	//std::vector<ValueType> vec(a, a + n);
	std::vector<float> v(Terrain->GetHeights(), Terrain->GetHeights() + Terrain->GetNumberHeights());
	
	//&data[0],btScalar(1),btScalar(-100),btScalar(100),1,PHY_FLOAT,false
	cout<<"\n WIDTH"<<Terrain->GetLength()<<"\n";
	cout<<"\n Data = "<<v[60*60]<<"\n";
	//GroundCollide = new CollisionHeightMap(Terrain->GetWidth(),Terrain->GetLength(),v,-100,100,1);
	//GroundCollide->Translate(32.5*20,30,27.5*20);
	//GroundCollide->Scale(1,1,1);

	(*pGraphicsEng)->Start();
	
	/*===== AI INITIALISATION =====*/
	Enemy1 = new AIObject(Vector2D(200, 200), Vector2D(0, 10), 0);
	Enemy2 = new AIObject(Vector2D(300, 300), Vector2D(10, 0), 0);

	Enemy1->SetTarget(Player);
	Enemy2->SetTarget(Player);

	(*AIScripting::GetInstance())->LoadScript("luascripts/statemachine.lua");

	luabind::object state = luabind::globals((*AIScripting::GetInstance())->lState);

	Enemy1->GetFSM()->SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
	Enemy1->GetFSM()->ChangeState(luabind::object_cast<luabind::object>(state["state_idle"]));

	Enemy2->GetFSM()->SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
	Enemy2->GetFSM()->ChangeState(luabind::object_cast<luabind::object>(state["state_idle"]));

	(*AIObjectManager::GetInstance())->RegisterObject(Enemy1);
	(*AIObjectManager::GetInstance())->RegisterObject(Enemy2);

	// TODO assign models to the enemy objects
}

void Game::Display()
{
	
	//Terrain = new HeightMap;
	//Terrain->Load("heightmap.bmp");
	//Terrain->ComputeFloats();
	//call display stuff
	
	//list<GameObject*>::iterator i;
	(*pGraphicsEng)->RenderTerrain(Terrain);
	//for(i = PropObjects.begin(); i != PropObjects.end(); ++i)
	//{
	//	(*pGraphicsEng)->RenderModel(*i);

//	}
	(*pGraphicsEng)->RenderModel(Knight);
//<<<<<<< HEAD
//	(*pGraphicsEng)->RenderModel(TestProp);
	//(*pGraphicsEng)->RenderModel(Skybox);
	//(*pGraphicsEng)->RenderModel(Knight);
//=======
	//(*pGraphicsEng)->RenderModel(TestProp);
	//(*pGraphicsEng)->RenderModel(Skybox);
//>>>>>>> stuff
}

void Game::Update()
{
	cout<<"Update \n wkjerg;jdfgh \n";
	// 
	GroundCollide->Update();
	Input();
	Player->Update(Terrain->GetY(Player->GetPosition().x,Player->GetPosition().z));
	CollisionWorldSingleton::Instance()->StepWorld();
	(*pGraphicsEng)->SetCam(Player->GetPosition());
	(*pGraphicsEng)->SetLook(Player->GetLookAt());

	(*AIObjectManager::GetInstance())->UpdateAI(1.0/20.0);
	
	//cout<<Player->GetPosition().x<<"   "<<Player->GetPosition().y<<"    "<<Player->GetPosition().z<<"\n";
	//cout<<"=================="<<Player->GetLookAt().x<<"\n";
}
void Game::MouseMove(int x, int y)
{
	Player->MouseMove(x,y);



}

void Game::Input()
{
	if((!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))) &&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100)))&&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115)))&&(!((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(119))))
	{
		//cout<<"NOTHING";
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
		
		//(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,-0.1));s
		Player->MovePlayer(1);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(115))
	{
		//(*pGraphicsEng)->MoveCamera(true, glm::vec3(0,0,0.1));
		Player->MovePlayer(2);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(100))
	{
		//(*pGraphicsEng)->MoveCamera(true, glm::vec3(0.1,0,0));
		Player->MovePlayer(4);
	}
	else if((*(*Input::GetInstance())->GetKeyboard()).IsKeyDown(97))
	{
		//(*pGraphicsEng)->MoveCamera(true, glm::vec3(-0.1,0,0));
		//cout<<"left";
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
		//cout<<"NOTHING";
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
