#pragma once

#include "Event.h"

class testEvent : Object
{

public:
	event encodeit;

	testEvent() : Object() {

	}

	void Encode() {

		std::cout << "encoding" << std::endl;
		onEncoded(); /// notify Event subscribers 
	}

	std::string ToString() override
	{
		return "testEvent";
	}

private:

	void onEncoded() {

		if (!encodeit.isEmpty())
		{
			encodeit(this, new Event_Args("default"));
		}

	}



};

