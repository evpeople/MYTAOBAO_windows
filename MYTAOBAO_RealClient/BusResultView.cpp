#include "BusResultView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Goods.h"
#include<iostream>
using namespace std;

void BusResultView::show()
{
    showGoods();
    viewInput();
}

void BusResultView::viewInput()
{
    std::regex regexSec("[1234]");
    int choice;
    ViewManger& viewManger = ViewManger::getInstance();
    input(choice, "尊敬的商家\n1\t更改商品\n2\t打折\n3\t登出\n4\t更改密码\n", regexSec);
    enum class CHOICEEVENT
    {
        GOODS = 1, DISCOUNT, LOGOUT, CHANGEPASS
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::GOODS:
        viewManger.setNext(make_unique<BusinessmanView>());
        break;
    case CHOICEEVENT::DISCOUNT:
        viewManger.setNext(make_unique<DisCountView>());
        break;
    case CHOICEEVENT::LOGOUT:
        viewManger.setNext(make_unique<LogoutView>());
        break;
    case CHOICEEVENT::CHANGEPASS:
        viewManger.setNext(make_unique<ChangePassView>());
        break;
    default:
        viewManger.setNext(make_unique<FailureView>());
        break;
    }
}

bool BusResultView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
