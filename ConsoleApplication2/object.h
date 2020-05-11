#pragma once
#include<string>


class Object {

public:
	virtual std::string ToString() = 0;


	virtual ~Object() {

	}
};

using object = Object*;