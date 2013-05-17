#include "StdAfx.h"
#include "CommonFunctions.h"

namespace CommonFunctions
{
	std::string CheckFile(const std::string &sInitialName)
	{
		//This block of code can be duplicated to check multiple file locations, either sequentially or with the input of the location to check.
		std::string sFileName = "data\\" + sInitialName;
		std::ifstream testFile(sFileName.c_str());
		if(testFile.is_open())
		{
			return sFileName;
		}
		// if nothing returned, file unable to be opened throw error
		throw std::runtime_error("File: " + sInitialName +  " not found.");
	};

	float GetMaximum(float a, float b)
	{
		if(a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
}