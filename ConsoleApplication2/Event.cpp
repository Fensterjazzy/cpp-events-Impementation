#include "Event.h"

void event::operator+=(funcptr func)
{
	handleEvent.push_back(func);
}

void event::Add(funcptr func)
{
	handleEvent.push_back(func);
}

void event::operator() (object source, EventArgs* args)
{

	eventIterator = handleEvent.begin();

	for (; eventIterator != handleEvent.end(); ++eventIterator)
	{
		(*eventIterator)(source, args);
	}
}

bool event::isEmpty()
{
	return handleEvent.empty();
}