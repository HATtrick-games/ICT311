#pragma once

#include <vector>
#include <iostream>
#include <string>

#include <boost/scoped_ptr.hpp>

/**
 * \class	DynamicEnum
 *
 * \brief	Dynamic enum.
**/
class DynamicEnum
{
public:

	/**
	 * \fn	void DynamicEnum::AddValue(std::string description);
	 *
	 * \brief	Adds a value.
	 *
	 * \param	description	The description.
	**/
	void AddValue(std::string description);

	/**
	 * \fn	int DynamicEnum::GetValue(std::string description);
	 *
	 * \brief	Gets the value specified by the specified description.
	 *
	 * \param	description	The description.
	 *
	 * \return	The value.
	**/
	int GetValue(std::string description);

	/**
	 * \fn	std::string DynamicEnum::GetDescription(int value);
	 *
	 * \brief	Gets a description.
	 *
	 * \param	value	The value.
	 *
	 * \return	The description.
	**/
	std::string GetDescription(int value);

	/**
	 * \fn	static boost::scoped_ptr<DynamicEnum>* DynamicEnum::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \return	null if it fails, else the instance.
	**/
	static boost::scoped_ptr<DynamicEnum>* GetInstance();

	/**
	 * \fn	friend std::ostream& DynamicEnum::operator<<(std::ostream& os, DynamicEnum& dn);
	 *
	 * \brief	Stream insertion operator.
	 *
	 * \param [in,out]	os	The operating system.
	 * \param [in,out]	dn	The dn.
	 *
	 * \return	The shifted result.
	**/
	friend std::ostream& operator<<(std::ostream& os, DynamicEnum& dn);
private:
	std::vector<std::string> values;	//!< The values

	static boost::scoped_ptr<DynamicEnum> singleton;	//!< The singleton
};

inline std::ostream& operator<<(std::ostream& os, DynamicEnum& dn)
{
	std::string out = "";
	int count = 0;
	std::vector<std::string>::iterator vectorIterator;

	for(vectorIterator = dn.values.begin(); vectorIterator != dn.values.end(); vectorIterator++)
	{
		os << count << " " << *vectorIterator << std::endl;
		count++;
	}

	return os;
}
