#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "GraphicsFact.h"
#include "IAsset.h"
#include "Input.h"
#include "IKeyboard.h"
#include "PlayerObject.h"
#include "CollisionWorldSingleton.h"
#include "GroundObject.h"

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

	Graphics* GraphicsEng;

	Mesh* Test;
};

