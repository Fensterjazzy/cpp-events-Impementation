#pragma once
#include<string>


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