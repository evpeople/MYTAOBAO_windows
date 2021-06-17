#include "LogoutView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Server.h"
#include<iostream>
using namespace std;
void LogoutView::show()
{
    showGoods();
    viewInput();
}

void LogoutView::viewInput()
{
    ViewManger& viewManger = ViewManger::getInstance();
    string choice;
    input(choice, "记得下次继续使用我哦！\n 输入q退出软件，输入其他回到主页面");
    if (choice != "q")
    {
        viewManger.setNext(make_unique<MainView>());
    }
    else
    {   
        closesocket(Server::sockS);
    }
}

bool LogoutView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}