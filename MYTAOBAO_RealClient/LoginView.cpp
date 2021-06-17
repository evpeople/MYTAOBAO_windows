#include "LoginView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Server.h"
#include<iostream>
using namespace std;
enum class PEOPLETYPE
{
    BUS = 1, CUS = 2
};
void LoginView::show()
{
    showGoods();
    viewInput();
}

void LoginView::viewInput()
{
    string name, password;
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[12]");
    std::regex regexSec("[1234]");
    input(choice, "1\t以商人身份登录\n2\t以顾客身份登录\n", regexFir);
    cin.get();
    input(name, "请输入用户名");
    input(password, "请输入密码");
    if (dealInput(name, password, choice))
    {
        switch ((PEOPLETYPE)choice)
        {
        case PEOPLETYPE::BUS:
            viewManger.sleepMs(250);
            viewManger.setNext(make_unique<BusResultView>());
            break;
        case PEOPLETYPE::CUS:
            viewManger.sleepMs(250);
            viewManger.setNext(make_unique<CusResultView>());
            break;

        default:
            cout << "something wrong" << endl;
        }
    }
    else
    {
        cout << "用户名不存在或密码错误" << endl;
        viewManger.sleepMs(1000);
        viewManger.setNext(make_unique<MainView>());
    }
}

bool LoginView::dealInput(string name, string pass, int choice)
{
    switch (PEOPLETYPE(choice))
    {
    case PEOPLETYPE::BUS:
        Usr = std::move(make_unique<Businessman>());
        break;
    case PEOPLETYPE::CUS:
        Usr = std::move(make_unique<Customer>());
        break;
    default:
        break;
    }
    char a[200];
    recv(Server::sockS, a, 200, 0);
    if (a[0] - '0' == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}