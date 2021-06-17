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

    ViewManger& viewManger = ViewManger::getInstance(getId());
    std::regex regexFir("[12]");
    input(choice, "1\t���������ע��\n2\t�Թ˿����ע��\n", regexFir);

    while (true)
    {
        input(name, "�������û���");
        //cin >> name;
        if (isExist(name, choice))
        {
            string temp = "0it has been used\n";
            send(Server::sockS[getId()], temp.c_str(), temp.size(),0);
            cout << "\n���û����ѱ�ռ�ã�����ѡ�������û���" << endl;
            continue;
        }
        else
        {
            string temp = "it has been used\n";
            send(Server::sockS[getId()], temp.c_str(), temp.size(), 0);
        }
        break;
    }

    while (true)
    {
        input(password, "����������");
        input(password2, "���ٴ���������");
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
           
        Usr = std::move(make_unique<Businessman>(name, pass));
        Usr->addGoods();
        Usr->storage();
        cout << "�������" << endl;
        break;
    }
    case PEOPLETYPE::CUS:
    {
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
        return false;
        break;
    }
}