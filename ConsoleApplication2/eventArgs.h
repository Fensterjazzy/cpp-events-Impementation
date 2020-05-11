#pragma once
#include <string>
class EventArgs
{

public:

	EventArgs(std::string na)
	{
		this->name = na;
	}

	std::string empty = "";

	std::string name;

};
