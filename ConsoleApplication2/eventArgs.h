#pragma once
#include <string>
class Event_Args
{

public:

	Event_Args() {
		name = "";
	}

	Event_Args(std::string na)
	{
		this->name = na;
	}

	std::string name;

	~Event_Args() {

	}

};

using EventArgs = Event_Args*;