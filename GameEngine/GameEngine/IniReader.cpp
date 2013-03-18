#include "IniReader.h"


IniReader::IniReader(TCHAR* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, _tcslen(szFileName));	
}

int IniReader::ReadInteger(TCHAR* szSection, TCHAR* szKey, int iDefaultValue)
{
	int iResult = GetPrivateProfileInt(szSection,  szKey, iDefaultValue, m_szFileName); 
	return iResult;
}

float IniReader::ReadFloat(TCHAR* szSection, TCHAR* szKey, float fpDefaultValue)
{
	TCHAR szResult[255];
	TCHAR szDefault[255];
	float fltResult;
	_stprintf(szDefault, _T("%f"),fpDefaultValue);
	GetPrivateProfileString(szSection,  szKey, szDefault, szResult, 255, m_szFileName); 
	fltResult =  _tstof(szResult);
	return fltResult;
}

bool IniReader::ReadBoolean(TCHAR* szSection, TCHAR* szKey, bool bDefaultValue)
{
	TCHAR szResult[255];
	TCHAR szDefault[255];
	bool bolResult;
	_stprintf(szDefault, _T("%s"), bDefaultValue? "True" : "False");
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName); 
	bolResult =  (_tcscmp(szResult, _T("True")) == 0 || 
				_tcscmp(szResult, _T("true")) == 0) ? true : false;
	return bolResult;
}

TCHAR* IniReader::ReadString(TCHAR* szSection, TCHAR* szKey, const TCHAR* szDefaultValue)
{
	TCHAR* szResult = new TCHAR[255];
	memset(szResult, 0x00, 255);
	GetPrivateProfileString(szSection,  szKey, 
				szDefaultValue, szResult, 255, m_szFileName); 
	return szResult;
}