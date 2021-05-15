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
    input(choice, "�𾴵Ŀ���\n1\t�鿴������Ϣ\n2\t������Ʒ\n3\t�ǳ�\n4\t��������\n", regexSec);
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
