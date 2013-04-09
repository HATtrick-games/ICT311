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

glm::mat3 AngleMath::RotateX(float Angle)
{
	glm::mat3 RotationMatrix(1.0f);
	Angle = DegreeToRadian(Angle);
	float Cos = cosf(Angle);
	float Sin = sinf(Angle);
	RotationMatrix[1].y = Cos;
	RotationMatrix[2].y = -Sin;
	RotationMatrix[1].z = Sin;
	RotationMatrix[2].z = Cos;

	return RotationMatrix;
}

glm::mat3 AngleMath::RotateY(float Angle)
{
	glm::mat3 RotationMatrix(1.0f);
	Angle = DegreeToRadian(Angle);
	float Cos = cosf(Angle);
	float Sin = sinf(Angle);
	RotationMatrix[0].x = Cos;
	RotationMatrix[0].z = -Sin;
	RotationMatrix[2].x = Sin;
	RotationMatrix[2].z = Cos;

	return RotationMatrix;
}

glm::mat3 AngleMath::RotateZ(float Angle)
{
	glm::mat3 RotationMatrix(1.0f);
	Angle = DegreeToRadian(Angle);
	float Cos = cosf(Angle);
	float Sin = sinf(Angle);
	RotationMatrix[0].x = Cos;
	RotationMatrix[1].x = -Sin;
	RotationMatrix[0].y = Sin;
	RotationMatrix[1].y = Cos;

	return RotationMatrix;
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