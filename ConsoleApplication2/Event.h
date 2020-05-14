#pragma once

#include "eventArgs.h"
#include "myarray.h"
#include "object.h"

///
///Generics to be implemented...

using namespace davics;  ///<<<

template<typename TEvent>
class event
{

public:

	using funcptr = void (*) (object source, typename TEvent* args);

	myarray<funcptr>* handleEvent;

public:

	event()
	{
		try {

			handleEvent = new myarray<funcptr>(1); /// default value of 1 memory slot for event delegates
		}

		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	event(int siz)
	{
		try {

			handleEvent = new myarray<funcptr>(siz);  /// set the size of the memory slot for event delegates
		}

		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
		}
	}

	event operator = (const event& other) {

		this = other;
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


template<typename TEvent>
void event<TEvent>::operator+=(funcptr func)
{
	try {
		handleEvent->Add(func);
	}

	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}

	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}

template<typename TEvent>
void event<TEvent>::Add(funcptr func)
{

	try {
		handleEvent->Add(func);
	}

	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}

	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}

}

template<typename TEvent>
void event<TEvent>::operator() (object source, typename TEvent* args)
{
	try {

		handleEvent->ArrayPtr = handleEvent->begin();

		for (int index = 0; index != handleEvent->Position; ++index)
		{
			handleEvent->ArrayPtr[index](source, args);
		}
	}

	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}

}

template<typename TEvent>
void event<TEvent>::unSubscribe(funcptr func)
{
	try {
		handleEvent->Remove(func);
	}

	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}

	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}
}

template<typename TEvent>
bool event<TEvent>::isEmpty()
{
	try {

		return handleEvent->empty();
	}

	catch (std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}

}