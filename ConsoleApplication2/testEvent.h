#pragma once

#include "Event.h"

///@Brief object base Class for all classes implementing events for the ToString() method call;
class testEvent : Object
{

public:

	event encodeit; /// declare event..

	testEvent() : Object() {}

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

		this->encodeit.isEmpty();

		///if event encodeit is not empty -> has subscribers
		if (!this->encodeit.isEmpty())
		{
			this->encodeit(this, new Event_Args("default"));  /// call event functions for its list		...
		}

	}
};

