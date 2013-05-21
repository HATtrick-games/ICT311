#include "StdAfx.h"
#include "Game.h"

boost::scoped_ptr<Game> Game::pSingleton(NULL);

Game::Game()
{
	Player = new PlayerObject(glm::vec3(0,10,0),glm::vec3(0,3,-1),glm::vec3(0,1,0));
	//Obj = new GameObject();
	//Obj->InitialiseCollisionBody(glm::vec3(0,3,-50));
	plane = new GroundObject();
	plane->InitialiseCollisionBody(glm::vec3(0,10,0));
}

void Game::Init()
{
	GraphicsFact GraphicsFactory;
	pGraphicsEng = GraphicsFactory.CreateEngine("OpenGL");
	(*pGraphicsEng)->Initialise();
	(*Input::GetInstance())->SetInputMethod("OPENGL");

	Skybox = new GameObject;
	TestProp = new GameObject;
	Knight = new GameObject;

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
//<<<<<<< HEAD

	Knight->SetMesh(new Mesh);
	(Knight->GetMesh())->SetFile("./data/KnightDefault.obj");
	(Knight->GetMesh())->Load();
	Knight->SetPosition(glm::vec3(0,0,-4));
	Knight->SetScale(glm::vec3(0.05,0.05,0.05));
	Knight->SetRotation(glm::vec3(0,0,0));

//=======
	//TestProp->InitialiseCollisionBody();
	//Skybox->InitialiseCollisionBody();
//>>>>>>> stuff

	Terrain = new HeightMap;
	Terrain->Load("heightmap2.bmp");
	//std::vector<ValueType> vec(a, a + n);
	std::vector<float> v(Terrain->GetHeights(), Terrain->GetHeights() + Terrain->GetNumberHeights());
	
	//&data[0],btScalar(1),btScalar(-100),btScalar(100),1,PHY_FLOAT,false
	cout<<"\n WIDTH"<<Terrain->GetLength()<<"\n";
	cout<<"\n Data = "<<v[60*60]<<"\n";
	GroundCollide = new CollisionHeightMap(Terrain->GetWidth(),Terrain->GetLength(),v,-100,100,1);
	//GroundCollide->Translate(32.5*20,30,27.5*20);
	//GroundCollide->Scale(20,20,20);

	(*pGraphicsEng)->Start();
	

}

void Game::Display()
{
	//Terrain = new HeightMap;
	//Terrain->Load("heightmap.bmp");
	//Terrain->ComputeFloats();
	//call display stuff
	
	//
	(*pGraphicsEng)->RenderTerrain(Terrain);
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
	GroundCollide->Update();
	Input();
	Player->Update();
	CollisionWorldSingleton::Instance()->StepWorld();
	(*pGraphicsEng)->SetCam(Player->GetPosition());
	(*pGraphicsEng)->SetLook(Player->GetLookAt());
	
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

}

boost::scoped_ptr<Game> * Game::GetInstance()
{
	if(pSingleton.get() == NULL)
	{
		pSingleton.reset(new Game);
	}
	return &pSingleton;
}
