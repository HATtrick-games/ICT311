#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "OpenGL.h"

class GraphicsFact
{
public:

	/**
	 * \fn	GraphicsFact::GraphicsFact(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	GraphicsFact(void);

	/**
	 * \fn	GraphicsFact::~GraphicsFact(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 */

	~GraphicsFact(void);

	/**
	 * \fn	boost::scoped_ptr<Graphics> * GraphicsFact::CreateEngine(std::string Name);
	 *
	 * \brief	Creates an engine.
	 *
	 * \author	Chaokel
	 * \date	23/05/2013
	 *
	 * \param	Name	The name.
	 *
	 * \return	null if it fails, else the new engine.
	 */

	boost::scoped_ptr<Graphics> * CreateEngine(std::string Name);
};

