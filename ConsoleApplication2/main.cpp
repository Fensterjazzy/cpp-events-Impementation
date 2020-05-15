#include <iostream>
#include"testEvent.h"

#include"myLinkedList.h"

using namespace davicsList;

#pragma region Testclasses for subscribers

class message1 {

public:

	static void cal(object source, myEventArgs* args)
	{

		std::cout << "from message1 ";
		std::cout << source->ToString() << " " << args->name << " " << args->About << std::endl;
	}

};

class message2 {

public:

	static void cal(object source, myEventArgs* args)
	{
		std::cout << "from message2 ";
		std::cout << source->ToString() << " " << args->name << " " << args->About << std::endl;
	}

};

#pragma endregion


#pragma region Test function for subscribers

void cal(object source, myEventArgs* args)
{
	std::cout << "from Regular function ";
	std::cout << source->ToString() << " " << args->name << " " << args->About << std::endl;
}

#pragma endregion

int main()
{
	testEvent mytestevent; /// publisher

	message1 testMessage1;
	message2 testMessage2;

	mytestevent.encodeit += testMessage1.cal; //subscriber
	mytestevent.encodeit.Add(testMessage2.cal); //subscriber
	mytestevent.encodeit += cal; //subscriber

	mytestevent.encodeit.unSubscribe(cal); /// unsubscribe from event
	mytestevent.encodeit.unSubscribe(testMessage2.cal); /// unsubscribe from event

	mytestevent.encodeit += cal; //subscriber

	mytestevent.Encode();



}



