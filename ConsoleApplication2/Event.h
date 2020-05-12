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

#pragma region Subscribe to event
	///@ Brief funcptr = void (*) (object source, EventArgs args);
	void operator+=(funcptr func);

	void Add(funcptr func);
#pragma endregion


#pragma region UnSubscribe from event
	void unSubscribe(funcptr func);
#pragma endregion


#pragma region call all Event Functions
	void operator() (object source, EventArgs args);  ///object->obeject.h , EventArgs->eventArgs.h
#pragma endregion


#pragma region Check event Buffer if its Empty or not
	bool isEmpty();
#pragma endregion



};
