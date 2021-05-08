#include "ViewManger.h"
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
	ViewManger a = t;
	return a;
}

	//todo: 需要给每个View建立好单例的对象，然后直接set过去；
