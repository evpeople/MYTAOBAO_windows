#include "DisCountView.h"
#include"ViewManger.h"
#include"Views.h"

#include<iostream>
using namespace std;
void DisCountView::show()
{
    showGoods();
    viewInput();
}

void DisCountView::viewInput()
{
    string kind;
    ViewManger& viewManger = ViewManger::getInstance();
    cout << "�����뽫Ҫ���۵�Ʒ��" << endl;
    cin >> kind;
    Usr->discount(kind);
    cout << "�������" << endl;
    viewManger.setNext(make_unique<BusResultView>());
    
}

bool DisCountView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
