#pragma once

#include <map>
#include <string>
#include <boost/scoped_ptr.hpp>

#include "AIObject.h"

/**
 * \class	AIObjectManager
 *
 * \brief	Manages all the AI objects for use with the messaging system.
**/
class AIObjectManager
{
public:
	void RegisterObject(AIObject* object);

	/**
	 * \fn	AIObject* AIObjectManager::GetObjectFromID(int id);
	 *
	 * \brief	Gets the AI object from identifier.
	 *
	 * \param	id	The identifier.
	 *
	 * \return	null if it fails, else the object from identifier.
	**/
	AIObject* GetObjectFromID(int id);

	/**
	 * \fn	void AIObjectManager::RemoveObject(AIObject* object);
	 *
	 * \brief	Removes the AI object described by object.
	 *
	 * \param [in,out]	object	If non-null, the object.
	**/
	void RemoveObject(AIObject* object);

	/**
	 * \fn	static boost::scoped_ptr<AIObjectManager>* AIObjectManager::GetInstance();
	 *
	 * \brief	Gets the singleton instance of this class.
	 *
	 * \return	null if it fails, else the instance.
	**/
	static boost::scoped_ptr<AIObjectManager>* GetInstance();
private:
	std::map<int, AIObject*> objectMap; //!< The AI object map

	static boost::scoped_ptr<AIObjectManager> singleton;	//!< The singleton object
};
