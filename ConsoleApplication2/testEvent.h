#pragma once

#include "Event.h"

///test
class myEventArgs : public Event_Args {

public:

	myEventArgs() = default;

	myEventArgs(std::string name) :Event_Args(name) {}

	std::string About{ "Demo test" };

	~myEventArgs()
	{

	}
};


///@Brief object base Class for all classes implementing events for the ToString() method call;
class testEvent : Object
{

public:

	event<myEventArgs> encodeit; /// dynamic event handler

	testEvent() = default;

	void Encode() {

		std::cout << "encoding" << std::endl;
		onEncoded(); /// notify Event subscribers 
	}

	std::string ToString() override
	{
		return "DavicsEvent";
	}

private:

	void onEncoded() {

		this->encodeit.isEmpty();

		///if event encodeit is not empty -> has subscribers
		if (!this->encodeit.isEmpty())
		{
			this->encodeit(this, new myEventArgs("my new EventArgs class"));  /// call event functions for its list		...
		}

	}
};

