#pragma once
#include <tchar.h>
#include <iostream>
#include <Windows.h> 

class IniWriter
{
public:
	IniWriter(TCHAR* szFileName); 
	void WriteInteger(TCHAR* szSection, TCHAR* szKey, int iValue);
	void WriteFloat(TCHAR* szSection, TCHAR* szKey, float fpValue);
	void WriteBoolean(TCHAR* szSection, TCHAR* szKey, bool bValue);
	void WriteString(TCHAR* szSection, TCHAR* szKey, TCHAR* szValue);
private:
	TCHAR m_szFileName[255];
};

