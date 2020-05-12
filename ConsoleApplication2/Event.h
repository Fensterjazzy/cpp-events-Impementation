#pragma once

#include "eventArgs.h"
#include<list>
#include "object.h"

///template<class TEvent> 
///Generics to be implemented...
class event
{

private:
	using funcptr = void (*) (object source, EventArgs args);

	using EventHandler = std::list<funcptr>;

	EventHandler handleEvent;
	EventHandler::iterator eventIterator;

public:

	///@ Brief funcptr = void (*) (object source, EventArgs args);
	void operator+=(funcptr func);

	void Add(funcptr func);

	void operator() (object source, EventArgs args);  ///object->obeject.h , EventArgs->eventArgs.h

	bool isEmpty();
};
