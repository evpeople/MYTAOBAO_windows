#include "ChangePassView.h"
#include"ViewManger.h"
#include"Views.h"
#include<iostream>
using namespace std;

enum class PEOPLETYPE
{
    BUS = 1, CUS = 2
};
void ChangePassView::show()
{
    showGoods();
    viewInput();
}

void ChangePassView::viewInput()
{
    ViewManger& viewManger = ViewManger::getInstance();

    string pass;
    cout << "请输入你原本的密码" << endl;
    cin >> pass;
    
    while (true)
    {

        if (Bus->getUsrName()!="0"&&Bus->auth(pass))
        {
            cout << "请输入您的新密码" << endl;
            cin >> pass;
            Bus->changePassWord(pass);
            break;
        }
        else if(Cus->auth(pass))
        {
            cout << "请输入您的新密码" << endl;
            cin >> pass;
            Cus->changePassWord(pass);
            break;
        }
    }
    cout << "更改成功" << endl;
    viewManger.setNext(make_unique<MainView>());
}

bool ChangePassView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
