#pragma once

#include "eventArgs.h"
#include "object.h"
#include"myLinkedList.h"


template<typename TEvent>
class event
{

private:

	using funcptr = void (*) (object source, typename TEvent* args);

	davics::LinkedList<funcptr> handleEvent;

public:

	event()
	{

	}

#pragma region Subscribe to event

	void operator+=(funcptr func);

	void Add(funcptr func);

#pragma endregion
	///...........

#pragma region UnSubscribe to event

	void unSubscribe(funcptr func);

#pragma endregion
	///...........

#pragma region call all Event Functions

	void operator() (object source, typename TEvent* args);

#pragma endregion
	///...........

#pragma region Check event Buffer if its Empty or not
	bool isEmpty();
#pragma endregion
	///...........

	~event()
	{

	}

};


#pragma region EvnentFunctions Definitions

template<typename TEvent>
void event<TEvent>::operator+=(funcptr func)
{

	handleEvent.Add(func);

}

template<typename TEvent>
void event<TEvent>::Add(funcptr func)
{

	handleEvent.Add(func);

}

template<typename TEvent>
void event<TEvent>::operator() (object source, typename TEvent* args)
{
	handleEvent.InitPointer();

	for (; handleEvent.getNextPointer() != nullptr; handleEvent.updatePointer())
	{
		handleEvent.startPointer(source, args);

	}

}

template<typename TEvent>
void event<TEvent>::unSubscribe(funcptr func)
{
	try {
		handleEvent.deleteNode(func);
	}

	catch (std::runtime_error e)
	{
		throw e;
	}

}

template<typename TEvent>
bool event<TEvent>::isEmpty()
{

	return handleEvent.empty();


}

#pragma endregion