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
            input(pass, "���������");
            Usr->changePassWord(pass);
            break;
        }
    }
    cout << "���ĳɹ�" << endl;
    viewManger.sleepMs(500);
    viewManger.setNext(make_unique<MainView>());
}

bool ChangePassView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
