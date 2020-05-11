#pragma once

#include "eventArgs.h"
#include<list>

///template<class TEvent> 
///Generics to be implemented...
class event
{

protected:
	typedef void* object;
	using funcptr = void (*) (object, EventArgs* args);

private:

	using EventHandler = std::list<funcptr>;

	EventHandler handleEvent;
	EventHandler::iterator eventIterator;

public:

	void operator+=(funcptr func);

	void Add(funcptr func);

	void operator() (object source, EventArgs* args);

	bool isEmpty();
};
