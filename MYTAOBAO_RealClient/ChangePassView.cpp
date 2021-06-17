#include "ChangePassView.h"
#include"ViewManger.h"
#include"Views.h"
#include<iostream>
#include"Server.h"
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
    input(pass, "输入你原本的密码");
    while (true)
    {
        char temp[30];
        recv(Server::sockS, temp, 30, 0);
        if (temp[0] - '0' == 1)
        {
            input(pass, "你的新密码");

            cout << "更改成功" << endl;
            break;
        }
        else
        {
            input(pass, "好好回忆你原本原本的密码，输入#则退出");
            if (pass == "#")
            {
                cout << "真完蛋，忘记密码了吧" << endl;
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