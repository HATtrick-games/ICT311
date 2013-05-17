#include "stdafx.h"
#include "IKeyboard.h"

void IKeyboard::DefineKey(std::string identifier, int key)
{
	mKeysDefined[identifier] = key;
}

void IKeyboard::UndefineKey(std::string identifier)
{
	mKeysDefined.erase(identifier);
}