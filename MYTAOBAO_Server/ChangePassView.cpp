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
    input(pass, "��ԭ��������");
    
    while (true)
    {

        if (Usr->getUsrName()!="0"&&Usr->auth(pass))
        {
            string temp = "1yyyyyyyyyyyyyyyyyyyyyyyyy";
            send(Server::sockS[getId()], temp.c_str(), temp.size(), 0);
            input(pass, "���������");
            Usr->changePassWord(pass);
            cout << "���ĳɹ�" << endl;
            break;
        }
        else
        {
            string temp = "0yyyyyyyyyyyyyyyyyyyyyyyyy";
            send(Server::sockS[getId()], temp.c_str(), temp.size(), 0);
            input(pass, "�úû�����ԭ��ԭ�������룬����#���˳�");
            if (pass == "#")
            {
                cout << "���군�����������˰�" << endl;
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
