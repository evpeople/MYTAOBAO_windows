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
    input(pass, "������ԭ��������");
    while (true)
    {
        char temp[30];
        recv(Server::sockS, temp, 30, 0);
        if (temp[0] - '0' == 1)
        {
            input(pass, "���������");

            cout << "���ĳɹ�" << endl;
            break;
        }
        else
        {
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