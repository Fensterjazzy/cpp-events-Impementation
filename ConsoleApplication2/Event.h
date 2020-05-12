#pragma once

#include "eventArgs.h"
#include<list>
#include "object.h"

///template<class TEvent> 
///Generics to be implemented...
template<typename TEvent>
class event
{

private:

	using funcptr = typename void (*) (object source, TEvent* args);

	using EventHandler = typename std::list<funcptr>;

	typename std::list<void (*) (object source, TEvent* args)> handleEvent;
	typename EventHandler::iterator eventIterator;

public:

#pragma region Subscribe to event
	///@ Brief funcptr = void (*) (object source, EventArgs args);
	void operator+=(funcptr func);

	void Add(funcptr func);
#pragma endregion


#pragma region UnSubscribe to event
	void unSubscribe(funcptr func);
#pragma endregion

#pragma region call all Event Functions

	void operator() (object source, TEvent* args);  ///object->obeject.h , EventArgs->eventArgs.h
#pragma endregion


#pragma region Check event Buffer if its Empty or not
	bool isEmpty();
#pragma endregion



};
