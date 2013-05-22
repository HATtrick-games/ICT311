#include "StdAfx.h"
#include "DynamicEnum.h"

boost::scoped_ptr<DynamicEnum> DynamicEnum::singleton(NULL);

void DynamicEnum::AddValue(std::string description)
{
	values.push_back(description);
}

int DynamicEnum::GetValue(std::string description)
{
	if(values.size() == 0)
		return -1;

	std::vector<std::string>::iterator vectorIterator;
	int count = 0;
	for(vectorIterator = values.begin(); vectorIterator != values.end(); vectorIterator++)
	{
		if(description == *vectorIterator)
			return count;

		count++;
	}

	return -1;
}

std::string DynamicEnum::GetDescription(int value)
{
	if(value > values.size() -1 || value < 0 || values.size() == 0)
	{
		return "INVALID MESSAGE";
	}
	else
	{
		return values[value];
	}
}

boost::scoped_ptr<DynamicEnum>* DynamicEnum::GetInstance()
{
	if(singleton.get() == NULL)
	{
		singleton.reset(new DynamicEnum);
	}
	return &singleton;
}