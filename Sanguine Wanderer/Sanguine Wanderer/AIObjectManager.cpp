#include "StdAfx.h"
#include "AIObjectManager.h"

boost::scoped_ptr<AIObjectManager> AIObjectManager::singleton(NULL);

void AIObjectManager::RegisterObject(AIObject* object)
{
	objectMap.insert(std::make_pair(object->GetID(), object));
}

void AIObjectManager::RemoveObject(AIObject* object)
{
	objectMap.erase(objectMap.find(object->GetID()));
}

AIObject* AIObjectManager::GetObjectFromID(int id)
{
	std::map<int,AIObject*>::const_iterator ent=objectMap.find(id);
	if(ent ==  objectMap.end())
	{
		return NULL;
	}
	return ent->second;
}

boost::scoped_ptr<AIObjectManager>* AIObjectManager::GetInstance()
{
	if(singleton.get() == NULL)
	{
		singleton.reset(new AIObjectManager);
	}
	return &singleton;
}