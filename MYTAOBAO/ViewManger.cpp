#include "ViewManger.h"
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

ViewManger& ViewManger::operator=(const ViewManger& t)
{
	ViewManger a ;
	return a;
}

