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
    input(choice, "1\t给Book打折\n2\t给Cloths打折\n3\t给EleProduct打折\n", regexFir);
    double discount;
    cout << "请输入打几折" << endl;
    BaseView::input(discount);
    discount = discount * 0.1;
    dealInput(choice, discount);
    cout << "打折完毕" << endl;
    viewManger.setNext(make_unique<BusResultView>());
    
}

bool DisCountView::dealInput(int choice,double discount)
{
    Usr->discount(choice, discount);
    return false;
}
