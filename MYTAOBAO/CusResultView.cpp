#include "CusResultView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Goods.h"
#include<iostream>
using namespace std;

void CusResultView::show()
{
    showGoods();
    viewInput();
}

void CusResultView::viewInput()
{
    std::regex regexSec("[1234]");
    int choice;
    ViewManger& viewManger = ViewManger::getInstance(); 
    input(choice, "尊敬的客人\n1\t查看个人信息\n2\t购买商品\n3\t登出\n4\t更改密码\n", regexSec);
    enum class CHOICEEVENT
    {
        INFO = 1, BUY, LOGOUT, CHANGEPASS
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::INFO:
        viewManger.setNext(make_unique<CustmomerView>());
        break;
    case CHOICEEVENT::BUY:
        viewManger.setNext(make_unique<BuyView>());
        break;
    case CHOICEEVENT::LOGOUT:
        viewManger.setNext(make_unique<LogoutView>());
        break;
    case CHOICEEVENT::CHANGEPASS:
        viewManger.setNext(make_unique<ChangePassView>());
    default:
        viewManger.setNext(make_unique<FailureView>());
        break;
    }
}

bool CusResultView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
