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
    cout << "请输入将要打折的品类" << endl;
    cin >> kind;
    Usr->discount(kind);
    cout << "设置完毕" << endl;
    viewManger.setNext(make_unique<BusResultView>());
    
}

bool DisCountView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
