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
    cout << "��������ԭ��������" << endl;
    cin >> pass;
    
    while (true)
    {

        if (Usr->getUsrName()!="0"&&Usr->auth(pass))
        {
            cout << "����������������" << endl;
            cin >> pass;
            Usr->changePassWord(pass);
            cout << "���ĳɹ�" << endl;
            break;
        }
        else
        {
            input(pass, "�úû�����ԭ��ԭ�������룬����#���˳�");
            if (pass=="#")
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
