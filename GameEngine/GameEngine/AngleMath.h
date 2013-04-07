#pragma once

#include <boost\scoped_ptr.hpp>

class AngleMath
{
public:
	AngleMath(void);
	~AngleMath(void);

	static boost::scoped_ptr<AngleMath>* GetInstance();

	float DegreeToRadian(float Degree);
	float RadianToDegree(float Radian);

private:
	double PI;
	float DegToRad;
	float RadToDeg;
	static boost::scoped_ptr<AngleMath> pAngleMathSingleton;
};

