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

        if (Bus->getUsrName()!="0"&&Bus->auth(pass))
        {
            cout << "����������������" << endl;
            cin >> pass;
            Bus->changePassWord(pass);
            break;
        }
        else if(Cus->auth(pass))
        {
            cout << "����������������" << endl;
            cin >> pass;
            Cus->changePassWord(pass);
            break;
        }
    }
    cout << "���ĳɹ�" << endl;
    viewManger.setNext(make_unique<MainView>());
}

bool ChangePassView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
