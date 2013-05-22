#pragma once

#include <map>
#include <string>
#include <boost/scoped_ptr.hpp>

#include "AIObject.h"

class AIObjectManager
{
public:
	void RegisterObject(AIObject* object);

	AIObject* GetObjectFromID(int id);

	void RemoveObject(AIObject* object);

	static boost::scoped_ptr<AIObjectManager>* GetInstance();
private:
	std::map<int, AIObject*> objectMap;

	static boost::scoped_ptr<AIObjectManager> singleton;
};
