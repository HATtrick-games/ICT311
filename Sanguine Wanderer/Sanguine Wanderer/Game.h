#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "GraphicsFact.h"
#include "IAsset.h"
#include "Input.h"
#include "IKeyboard.h"
#include "PlayerObject.h"
#include "CollisionWorldSingleton.h"
#include "HeightMap.h"
#include "GroundObject.h"
#include "PropObject.h"
#include "CollisionHeightMap.h"
#include "AIScripting.h"
#include <list>

class Game
{
public:
	 Game();
	~Game(void);

	void Display();
	void Init();
	void Input();
	void Update();
	void MouseMove(int x, int y);

	static boost::scoped_ptr<Game> * GetInstance();

private:
	static boost::scoped_ptr<Game> pSingleton;
	boost::scoped_ptr<Graphics> *pGraphicsEng;
	PlayerObject* Player;
	GameObject* Obj;
	GroundObject* plane;
	CollisionHeightMap* GroundCollide;

	Graphics* GraphicsEng;
	list<GameObject*>::iterator i;
	list<GameObject*> PropObjects;
	GameObject * TestProp;
	GameObject * Rock2;
	GameObject * Skybox;
	GameObject * Knight;
	AIObject* Enemy1;
	AIObject* Enemy2;
	HeightMap * Terrain;
};

