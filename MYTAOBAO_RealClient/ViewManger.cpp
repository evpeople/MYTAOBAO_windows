#include "ViewManger.h"
#include"Server.h"
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
        cin.ignore(1000, '\n');
        cin.sync();
        viewCurrent = std::move(viewNext);
        //Server::loadGoods();
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