#include "IMouse.h"

void IMouse::DefineButton(std::string identifier, int key)
{
	mButtonsDefined[identifier] = key;
}

void IMouse::UndefineButton(std::string identifier)
{
	mButtonsDefined.erase(identifier);
}