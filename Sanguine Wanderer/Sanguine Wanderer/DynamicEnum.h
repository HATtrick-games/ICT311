#pragma once

#include <vector>
#include <iostream>
#include <string>

#include <boost/scoped_ptr.hpp>

class DynamicEnum
{
public:
	void AddValue(std::string description);

	int GetValue(std::string description);

	std::string GetDescription(int value);

	static boost::scoped_ptr<DynamicEnum>* GetInstance();

	friend std::ostream& operator<<(std::ostream& os, DynamicEnum& dn);
private:
	std::vector<std::string> values;

	static boost::scoped_ptr<DynamicEnum> singleton;
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
