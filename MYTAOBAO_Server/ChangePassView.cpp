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
    ViewManger& viewManger = ViewManger::getInstance(getId());

    string pass;
    input(pass, "你原本的密码");
    
    while (true)
    {

        if (Usr->getUsrName()!="0"&&Usr->auth(pass))
        {
            string temp = "1yyyyyyyyyyyyyyyyyyyyyyyyy";
            send(Server::sockS[getId()], temp.c_str(), temp.size(), 0);
            input(pass, "你的新密码");
            Usr->changePassWord(pass);
            cout << "更改成功" << endl;
            break;
        }
        else
        {
            string temp = "0yyyyyyyyyyyyyyyyyyyyyyyyy";
            send(Server::sockS[getId()], temp.c_str(), temp.size(), 0);
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
