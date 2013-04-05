#pragma once


#include "Graphics.h"
#include "Input.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "CommonFuncs.h"

#include <boost\smart_ptr.hpp>

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

private:
	boost::scoped_ptr<Graphics> *pGraphicsEng;
	boost::scoped_ptr<Input> pInputEngine;
	static boost::scoped_ptr<Game> pGame;
};
/*
int main(int argc, char** argv)
{
	(*Game::GetInstance())->Initialise();
}*/