#include "ViewManger.h"
#include <thread>
#include <iostream>
#include <chrono>

using std::this_thread::sleep_for;
using namespace::std;

ViewManger& ViewManger::getInstance()
{
	static ViewManger instance;
	return instance;
}
void ViewManger::start()
{
	while (viewNext)
	{
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cin.sync();
		viewCurrent = std::move(viewNext);
		viewCurrent->show();
	}
}

void ViewManger::setNext(std::unique_ptr<BaseView> next)
{
	viewNext = std::move(next);
}

void ViewManger::sleepMs(int ms)
{
	sleep_for(std::chrono::milliseconds(ms));
}

ViewManger& ViewManger::operator=(const ViewManger& t)
{
	ViewManger a ;
	return a;
}

