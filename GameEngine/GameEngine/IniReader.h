#pragma once
#include <Windows.h>
#include <tchar.h>

#include <iostream>
#include <stdio.h>

class IniReader
{
public:
	IniReader(TCHAR* szFileName); 
	int ReadInteger(TCHAR* szSection, TCHAR* szKey, int iDefaultValue);
	float ReadFloat(TCHAR* szSection, TCHAR* szKey, float fpDefaultValue);
	bool ReadBoolean(TCHAR* szSection, TCHAR* szKey, bool bDefaultValue);
	TCHAR* ReadString(TCHAR* szSection, TCHAR* szKey, const TCHAR* szDefaultValue);
private:
	TCHAR m_szFileName[255];
};

