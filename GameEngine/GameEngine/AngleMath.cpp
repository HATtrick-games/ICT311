#include "AngleMath.h"

boost::scoped_ptr<AngleMath> AngleMath::pAngleMathSingleton(NULL);

AngleMath::AngleMath(void)
{
	PI = 3.141592653589793;
	DegToRad = PI / 180;
	RadToDeg =  180 / PI;
}

AngleMath::~AngleMath(void)
{
}

float AngleMath::DegreeToRadian(float Degree)
{
	return Degree * DegToRad;
}

float AngleMath::RadianToDegree(float Radian)
{
	return Radian * RadToDeg;
}

boost::scoped_ptr<AngleMath>* AngleMath::GetInstance(void)
{
	if(pAngleMathSingleton.get() == NULL)
	{
		pAngleMathSingleton.reset(new AngleMath);
	}
	return &pAngleMathSingleton;
}