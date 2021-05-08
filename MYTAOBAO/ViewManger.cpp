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

	//todo: ��Ҫ��ÿ��View�����õ����Ķ���Ȼ��ֱ��set��ȥ��
