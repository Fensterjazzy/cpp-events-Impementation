#pragma once
#include<string>

/// @Brief Interface class for all classes that implements an Event

class Object {

public:
	virtual std::string ToString() = 0;

	Object()
	{

	}
	virtual ~Object() {

	}
};

using object = Object*;