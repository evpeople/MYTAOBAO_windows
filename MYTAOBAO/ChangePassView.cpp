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
        if (Usr->getUsrName() != "0" && Usr->auth(pass))
        {
            cout << "请输入您的新密码" << endl;
            cin >> pass;
            Usr->changePassWord(pass);
            cout << "更改成功" << endl;
            break;
        }
        else
        {
            input(pass, "好好回忆你原本原本的密码，输入#则退出");
            if (pass == "#")
            {
                break;
            }
        }
    }
    viewManger.sleepMs(500);
    viewManger.setNext(make_unique<MainView>());
}

bool ChangePassView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}