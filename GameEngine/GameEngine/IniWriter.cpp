#include "IniWriter.h"

IniWriter::IniWriter(TCHAR* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, _tcslen(szFileName));
}
void IniWriter::WriteInteger(TCHAR* szSection, TCHAR* szKey, int iValue)
{
	TCHAR szValue[255];
	_stprintf(szValue, _T("%d"), iValue);
	WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName); 
}
void IniWriter::WriteFloat(TCHAR* szSection, TCHAR* szKey, float fpValue)
{
	TCHAR szValue[255];
	_stprintf(szValue, _T("%f"), fpValue);
	WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName); 
}
void IniWriter::WriteBoolean(TCHAR* szSection, TCHAR* szKey, bool bValue)
{
	TCHAR szValue[255];
	_stprintf(szValue, _T("%s"), bValue ? "True" : "False");
	WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName); 
}
void IniWriter::WriteString(TCHAR* szSection, TCHAR* szKey, TCHAR* szValue)
{
	WritePrivateProfileString(szSection,  szKey, szValue, m_szFileName);
}