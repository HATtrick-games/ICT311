#pragma once

#include <boost\scoped_ptr.hpp>
#include <glm\glm.hpp>

class AngleMath
{
public:
	AngleMath(void);
	~AngleMath(void);

	static boost::scoped_ptr<AngleMath>* GetInstance();

	float DegreeToRadian(float Degree);
	float RadianToDegree(float Radian);
	glm::mat3 RotateX(float Angle);
	glm::mat3 RotateY(float Angle);
	glm::mat3 RotateZ(float Angle);
	glm::mat3 CreateRotationMatrix(glm::vec3 Orientation);

	glm::mat4 CreateModelOrientationMatrix(glm::vec3 Orientation);

private:
	double PI;
	float DegToRad;
	float RadToDeg;
	static boost::scoped_ptr<AngleMath> pAngleMathSingleton;
};

