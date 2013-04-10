/**
 * \file	GraphicsEngFact.h
 *
 * \brief	Declares the graphics eng fact class.
 */

#pragma once

#include "Graphics.h"
#include "OpenGL.h"

/**
 * \class	GraphicsEngFact
 *
 * \brief	Graphics eng fact.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class GraphicsEngFact
{
public:

	/**
	 * \fn	GraphicsEngFact::GraphicsEngFact(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	GraphicsEngFact(void);

	/**
	 * \fn	GraphicsEngFact::~GraphicsEngFact(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~GraphicsEngFact(void);

	/**
	 * \fn	boost::scoped_ptr<Graphics> * GraphicsEngFact::CreateEngine(std::string Name);
	 *
	 * \brief	Creates an engine.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Name	The name.
	 *
	 * \return	null if it fails, else the new engine.
	 */

	boost::scoped_ptr<Graphics> * CreateEngine(std::string Name);
};

