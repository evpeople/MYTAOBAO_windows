#include "ViewManger.h"
#include"Server.h"
#include <thread>
#include <iostream>
#include <chrono>

using std::this_thread::sleep_for;
using namespace::std;

std::vector<ViewManger>ViewManger::viewS(2000);
ViewManger& ViewManger::getInstance(int ViewId)
{
	if (viewS[ViewId].getId()==ViewId)
	{
	return viewS[ViewId];
	}
	viewS[ViewId] = ViewManger();
	return viewS[ViewId];
}
void ViewManger::setId(int id)
{
	this->id = id;
}
int ViewManger::getId()
{
	return id;
}
ViewManger& ViewManger::operator=(const ViewManger& s)
{
        // 如果是对象本身, 则直接返回
	if (this == &s) {
		return *this;
	}

	// 复制等号右边对象的成员值到等号左边对象的成员
	this->id = s.id;
	if (viewCurrent==nullptr)
	{
		viewCurrent = make_unique<BaseView>();
		viewNext = make_unique <BaseView> ();
		viewCurrent->setId(id);
		viewNext->setId(id);
		return *this;
	}
	BaseView* temp = s.viewCurrent.get();
	BaseView* temp2 = s.viewNext.get();
	viewCurrent.reset(temp);
	viewNext.reset(temp2);
	viewCurrent->setId(id);
	viewNext->setId(id);

	return *this;
}

ViewManger::ViewManger(const ViewManger& s)
{
	id = s.id;
	if (viewCurrent == nullptr)
	{
		viewCurrent = make_unique<BaseView>();
		viewNext = make_unique <BaseView>();
		viewCurrent->setId(id);
		viewNext->setId(id);
		return;
	}
	BaseView* temp = s.viewCurrent.get();
	BaseView* temp2 = s.viewNext.get();
	viewCurrent.reset(temp);
	viewNext.reset(temp2);
	viewCurrent->setId(id);
	viewNext->setId(id);
}

void ViewManger::start()
{
	while (viewNext)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cin.sync();
			id = viewCurrent->getId();
		
		viewCurrent = std::move(viewNext);
		Server::loadGoods();
		viewCurrent->show();
	}
}
ViewManger::ViewManger()
{
	id = 0;
	viewCurrent = nullptr;
	viewCurrent = nullptr;
}
void ViewManger::setNext(std::unique_ptr<BaseView> next)
{
	viewNext = std::move(next);
	viewNext->setId(id);

}

void ViewManger::setNow(std::unique_ptr<BaseView> now)
{
	viewCurrent = std::move(now);
	viewCurrent->setId(id);
}

void ViewManger::sleepMs(int ms)
{
	sleep_for(std::chrono::milliseconds(ms));
}

