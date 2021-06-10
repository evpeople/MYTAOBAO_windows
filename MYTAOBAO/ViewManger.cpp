#include "ViewManger.h"
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;

ViewManger& ViewManger::getInstance()
{
	static ViewManger instance;
	return instance;
}
void ViewManger::start()
{
	while (viewNext)
	{
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

