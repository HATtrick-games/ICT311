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

class Game
{
public:
	 Game();
	~Game(void);

	void Display();
	void Init();
	void Input();
	void Update();

	static boost::scoped_ptr<Game> * GetInstance();

private:
	static boost::scoped_ptr<Game> pSingleton;
	boost::scoped_ptr<Graphics> *pGraphicsEng;
	PlayerObject* Player;

	Graphics* GraphicsEng;

	Mesh* Test;
	Mesh* Test2;
	HeightMap * Terrain;
};

