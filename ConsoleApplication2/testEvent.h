#pragma once

#include "Event.h"

class testEvent
{

public:
	event encodeit;


	void Encode() {

		std::cout << "encoding" << std::endl;
		onEncoded(); /// notify Event subscribers 
	}

	std::string ToString()
	{
		return "testEvent";
	}

private:

	void onEncoded() {

		if (!encodeit.isEmpty())
		{
			encodeit(this, new EventArgs("default"));
		}

	}

};

