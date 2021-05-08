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

	//todo: ��Ҫ��ÿ��View�����õ����Ķ���Ȼ��ֱ��set��ȥ��
