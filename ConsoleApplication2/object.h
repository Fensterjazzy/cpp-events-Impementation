#pragma once
#include<string>


class Object {

public:
	virtual std::string ToString() = 0;


	virtual ~Object() {

	}
};

typedef Object* object;