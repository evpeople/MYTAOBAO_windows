#include "LoginView.h"
#include"ViewManger.h"
#include"Views.h"
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
    std::cout << "请输入用户名" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> password;
    if (dealInput(name, password, choice))
    {
        switch ((PEOPLETYPE)choice)
        {
        case PEOPLETYPE::BUS:
            viewManger.setNext(make_unique<BusResultView>());
        case PEOPLETYPE::CUS:
            viewManger.setNext(make_unique<CusResultView>());
        default:
            cout << "something wrong" << endl;

        }
    }
    else
    {
        cout << "用户名不存在或密码错误" << endl;
        viewManger.setNext(make_unique<FailureView>());
    }
}

bool LoginView::dealInput(string name, string pass, int choice)
{
    switch (PEOPLETYPE(choice))
    {
    case PEOPLETYPE::BUS:
        return (*Usr)->login(name, pass);
        break;
    case PEOPLETYPE::CUS:
        return (*Usr)->login(name, pass);
        break;
    default:
        break;
    }
}
