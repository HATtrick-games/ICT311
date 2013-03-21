#pragma once

#include <map>
#include <list>
#include <string>

class IKeyboard
{
public:
	virtual void IsKeyDown(int key) = 0;
	virtual void IsKeyDown(std::string key) = 0;

	void Define(std::string identifier, int* keys);
	void Undefine(std::string identifier);
protected:
	std::map<std::string, std::list<int> > mKeysDefined;
};

void IKeyboard::Define(std::string identifier, int* keys)
{
	int x;

	while(*keys)
	{
		x = *keys++;
		mKeysDefined[identifier].push_back(x);
	}
}

void IKeyboard::Undefine(std::string identifier)
{
	mKeysDefined[identifier].clear();
}