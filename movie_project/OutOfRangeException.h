#pragma once

#include <string>
class OutOfRangeException
{
private:
	std::string msg;
public:
	OutOfRangeException(std::string msg)
	{
		this->msg = msg;
	}
};