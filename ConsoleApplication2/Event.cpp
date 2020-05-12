#include "Event.h"


template<typename TEvent>
void event<TEvent>::operator+=(funcptr func)
{
	handleEvent.push_back(func);
}

template<typename TEvent>
void event<TEvent>::Add(funcptr func)
{
	handleEvent.push_back(func);
}

template<typename TEvent>
void event<TEvent>::operator() (object source, TEvent* args)
{

	eventIterator = handleEvent.begin();

	for (; eventIterator != handleEvent.end(); ++eventIterator)
	{
		(*eventIterator)(source, args);
	}
}

template<typename TEvent>
void event<TEvent>::unSubscribe(funcptr func)
{
	handleEvent.remove(func);
}

template<typename TEvent>
bool event<TEvent>::isEmpty()
{
	return handleEvent.empty();
}