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
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[123]");
    input(choice, "1\t��Book����\n2\t��Cloths����\n3\t��EleProduct����\n", regexFir);
    double discount;
    cout << "���������" << endl;
    BaseView::input(discount);
    discount = discount * 0.1;
    dealInput(choice, discount);
    cout << "�������" << endl;
    viewManger.setNext(make_unique<BusResultView>());
    
}

bool DisCountView::dealInput(int choice,double discount)
{
    Usr->discount(choice, discount);
    return false;
}
