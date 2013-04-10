/**
 * \file	AngleMath.h
 *
 * \brief	Declares the angle mathematics class.
 */

#pragma once

#include <boost\scoped_ptr.hpp>
#include <glm\glm.hpp>

/**
 * \class	AngleMath
 *
 * \brief	Angle mathematics.
 *
 * \author	Hamish Carrier
 * \date	4/10/2013
 */

class AngleMath
{
public:

	/**
	 * \fn	AngleMath::AngleMath(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	AngleMath(void);

	/**
	 * \fn	AngleMath::~AngleMath(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 */

	~AngleMath(void);

	/**
	 * \fn	static boost::scoped_ptr<AngleMath>* AngleMath::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static boost::scoped_ptr<AngleMath>* GetInstance();

	/**
	 * \fn	float AngleMath::DegreeToRadian(float Degree);
	 *
	 * \brief	Degree to radian.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Degree	The degree.
	 *
	 * \return	.
	 */

	float DegreeToRadian(float Degree);

	/**
	 * \fn	float AngleMath::RadianToDegree(float Radian);
	 *
	 * \brief	Radian to degree.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Radian	The radian.
	 *
	 * \return	.
	 */

	float RadianToDegree(float Radian);

	/**
	 * \fn	glm::mat3 AngleMath::RotateX(float Angle);
	 *
	 * \brief	Rotate x coordinate.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Angle	The angle.
	 *
	 * \return	.
	 */

	glm::mat3 RotateX(float Angle);

	/**
	 * \fn	glm::mat3 AngleMath::RotateY(float Angle);
	 *
	 * \brief	Rotate y coordinate.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Angle	The angle.
	 *
	 * \return	.
	 */

	glm::mat3 RotateY(float Angle);

	/**
	 * \fn	glm::mat3 AngleMath::RotateZ(float Angle);
	 *
	 * \brief	Rotate z coordinate.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Angle	The angle.
	 *
	 * \return	.
	 */

	glm::mat3 RotateZ(float Angle);

	/**
	 * \fn	glm::mat3 AngleMath::CreateRotationMatrix(glm::vec3 Orientation);
	 *
	 * \brief	Creates rotation matrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Orientation	The orientation.
	 *
	 * \return	The new rotation matrix.
	 */

	glm::mat3 CreateRotationMatrix(glm::vec3 Orientation);

	/**
	 * \fn	glm::mat4 AngleMath::CreateModelOrientationMatrix(glm::vec3 Orientation);
	 *
	 * \brief	Creates model orientation matrix.
	 *
	 * \author	Hamish Carrier
	 * \date	4/10/2013
	 *
	 * \param	Orientation	The orientation.
	 *
	 * \return	The new model orientation matrix.
	 */

	glm::mat4 CreateModelOrientationMatrix(glm::vec3 Orientation);

private:

	/**
	 * \brief	The pi.
	 */

	double PI;

	/**
	 * \brief	The degrees to radians.
	 */

	float DegToRad;

	/**
	 * \brief	The radians to degrees.
	 */

	float RadToDeg;

	/**
	 * \brief	The angle mathematics singleton.
	 */

	static boost::scoped_ptr<AngleMath> pAngleMathSingleton;
};

