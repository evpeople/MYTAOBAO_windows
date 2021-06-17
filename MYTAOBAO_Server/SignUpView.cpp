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
    input(choice, "1\t以商人身份注册\n2\t以顾客身份注册\n", regexFir);

    while (true)
    {
        input(name, "请输入用户名");
        //cin >> name;
        if (isExist(name, choice))
        {
            string temp = "0it has been used\n";
            send(Server::sockS[getId()], temp.c_str(), temp.size(),0);
            cout << "\n此用户名已被占用，请您选择其他用户名" << endl;
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
        input(password, "请输入密码");
        input(password2, "请再次输入密码");
        if (password != password2)
        {
            cout << "两次密码不同，请重新注册" << endl;
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
        cout << "保存完毕" << endl;
        break;
    }
    case PEOPLETYPE::CUS:
    {
        //Customer temp{ name,pass,money };
        Usr = std::move(make_unique<Customer>(name, pass));
        Usr->storage();
        cout << "保存完毕" << endl;
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