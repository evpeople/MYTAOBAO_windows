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
    string pass;
    cout << "��������ԭ��������" << endl;
    cin >> pass;
    //while (true)
    //{
    //    if()
    //}

}

bool ChangePassView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
