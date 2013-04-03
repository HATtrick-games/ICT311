#pragma once

#include "Graphics.h"
#include "GameSettings.h"
#include "GraphicsEngFact.h"
#include "CommonFuncs.h"

#include <boost\smart_ptr.hpp>

/**
 * \class	Engine
 *
 * \brief	Sets up and initializes the graphics and input engines.
 */

class Engine
{
public:
	Engine(void);
	~Engine(void);

	virtual void Initialise();

	virtual void LoadResources() = 0;

	virtual void UnloadResources() = 0;

	virtual void Update(float time);

	virtual void Draw(float time);

	static Engine* GetEngine()
	{
		return currentEngine;
	}

	void Run();
protected:
	boost::scoped_ptr<Graphics> *pGraphicsEng;

private:
	static Engine* currentEngine;
};

