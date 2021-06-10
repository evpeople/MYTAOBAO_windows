#include "SignUpView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Goods.h"
#include<iostream>
using namespace std;
enum class PEOPLETYPE
{
    BUS = 1, CUS = 2
};
void SignUpView::show()
{
    showGoods();
    viewInput();
}

void SignUpView::viewInput()
{
    string name, password, password2;
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[12]");
    input(choice, "1\t���������ע��\n2\t�Թ˿����ע��\n", regexFir);

    while (true)
    {
        std::cout << "�������û���" << endl;
        cin >> name;
        if (isExist(name, choice))
        {
            cout << "\n���û����ѱ�ռ�ã�����ѡ�������û���" << endl;
            continue;
        }
        break;
    }

    while (true)
    {
        cout << "����������" << endl;
        cin >> password;
        cout << "���ٴ�ȷ����������" << endl;
        cin >> password2;
        if (password != password2)
        {
            cout << "�������벻ͬ��������ע��" << endl;
            continue;
        }
        break;
    }

    dealInput(name, password, choice);
    viewManger.sleepMs(500);
    viewManger.setNext(make_unique<MainView>());
}

bool SignUpView::dealInput(std::string name, std::string pass, int choice)
{
    switch ((PEOPLETYPE)choice)
    {
   case PEOPLETYPE::BUS:
   {
       //(**Usr) = Businessman{ name,pass,busSGooods,goodsType };
       //(*Usr)->storage();
       Usr = std::move(make_unique<Businessman>(name, pass));
       Usr->addGoods();
       Usr->storage();
       cout << "�������" << endl;
   }
   case PEOPLETYPE::CUS:
    {
        //double money;
        //cout << "�����ֵ����Ǯ" << endl;
        //cin >> money;
        //Customer temp{ name,pass,money };
        Usr = std::move(make_unique<Customer>(name, pass));
        Usr->storage();
        cout << "�������" << endl;
        break;
    }
    default:
        break;
    }
    return true;
}

bool SignUpView::isExist(string name, int choice)
{
    string inPath;
    ifstream fin;
    switch ((PEOPLETYPE)choice)
    {
    case PEOPLETYPE::BUS:
        inPath = Businessman::getAddress() + name + ".usr";
        fin.open(inPath);
        if (fin.is_open())
        {
            fin.close();
            return true;
        }
        else
        {
            return false;
        }
        break;
    case PEOPLETYPE::CUS:
        inPath = Customer::getAddress() + name + ".usr";
        fin.open(inPath);
        if (fin.is_open())
        {
            fin.close();
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        break;
    }
}