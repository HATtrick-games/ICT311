#pragma once

#include "AssetManager.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "CommonFuncs.h"
#include "Input.h"
#include "ScriptingEngine.h"
#include "CollisionWorldSingleton.h"

#include <iostream>

#include <boost\smart_ptr.hpp>

typedef std::map<std::string, GameObject*>::iterator objectMapIterator;

/**
 * \class	Game
 *
 * \brief	Sets up the game and implements the engine functions.
 */
class Game 
{
public:
	Game(void);
	~Game(void);

	void Initialise();

	void LoadResources();

	void UnloadResources();

	void Update(float time);

	void Draw();

	static boost::scoped_ptr<Game> * GetInstance();

	void AddGameObject(std::string id, GameObject* obj);

	void RemoveGameObject(std::string id);

private:
	boost::scoped_ptr<Graphics>* pGraphicsEng;

	static boost::scoped_ptr<Game> pGame;

	std::map<std::string, GameObject*> mGameObjects;

	/*** DELETE UPON COMPLETE ***/
	GameObject* testObject;
	GameObject* testObject1;
	Mesh* boxMesh;
	Mesh* boxMesh1;
};
/*
int main(int argc, char** argv)
{
	(*Game::GetInstance())->Initialise();
}*/