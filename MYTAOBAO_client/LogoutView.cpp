#include "LogoutView.h"
#include"ViewManger.h"
#include"Views.h"
#include<iostream>
using namespace std;
void LogoutView::show()
{
    showGoods();
    viewInput();
}

void LogoutView::viewInput()
{
    ViewManger& viewManger = ViewManger::getInstance(getId());
    string choice;
    input(choice, "�ǵ��´μ���ʹ����Ŷ��\n ����q�˳���������������ص���ҳ��");
    if (choice!="q")
    {
        viewManger.setNext(make_unique<MainView>());
    }
    closesocket(Server::sockS[getId()]);
}

bool LogoutView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
