#include <iostream>
#include<list>
#include"testEvent.h"


#pragma region Testclasses for subscribers

class message1 {

public:

	static void cal(object source, EventArgs args)
	{
		std::cout << "from message1";
		std::cout << source->ToString() << " " << args->name << std::endl;
	}

};

class message2 {

public:

	static void cal(object source, EventArgs args)
	{
		std::cout << "from message2";
		std::cout << source->ToString() << " " << args->name << std::endl;
	}

};

#pragma endregion


#pragma region Test function for subscribers

void cal(object source, EventArgs args)
{
	std::cout << "from Regular function";
	std::cout << source->ToString() << " " << args->name << std::endl;
}

#pragma endregion



int main()
{

	testEvent mytestevent; /// publisher

	message1 testMessage1;
	message2 testMessage2;

	mytestevent.encodeit += testMessage1.cal; //subscriber
	mytestevent.encodeit += testMessage2.cal; //subscriber
	mytestevent.encodeit += cal; //subscriber

	mytestevent.encodeit.unSubscribe(cal); /// remove
	mytestevent.encodeit.unSubscribe(testMessage2.cal); /// remove

	mytestevent.Encode();

}



