#include "LoginView.h"
#include"ViewManger.h"
#include"Views.h"
#include<iostream>
using namespace std;
enum class PEOPLETYPE
{
    BUS = 1, CUS = 2
};
void LoginView::show()
{
    showGoods();
    viewInput();
}

void LoginView::viewInput()
{
    string name, password;
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[12]");
    std::regex regexSec("[1234]");
    input(choice, "1\t以商人身份登录\n2\t以顾客身份登录\n", regexFir);
    std::cout << "请输入用户名" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> password;
    if (dealInput(name, password, choice))
    {
        switch ((PEOPLETYPE)choice)
        {
            //商人，则
        case PEOPLETYPE::BUS:
        {   input(choice, "尊敬的商家\n1\t更改商品\n2\t打折\n3\t登出\n4\t更改密码\n", regexSec);
            enum class CHOICEEVENT
            {
                GOODS=1,DISCOUNT,LOGOUT,CHANGEPASS
            };
            switch ((CHOICEEVENT)choice)
            {
            case CHOICEEVENT::GOODS:
                viewManger.setNext(make_unique<GoodsView>());
                break;
            case CHOICEEVENT::DISCOUNT:
                viewManger.setNext(make_unique<DisCountView>());
                break;
            case CHOICEEVENT::LOGOUT:
                viewManger.setNext(make_unique<LogoutView>());
                break;
            case CHOICEEVENT::CHANGEPASS:
                viewManger.setNext(make_unique<ChangePassView>());
            default:
                viewManger.setNext(make_unique<FailureView>());
                break;
            }
            break;
        //顾客，则
        }
        case PEOPLETYPE::CUS:
        {
            input(choice, "尊敬的客人\n1\t查看个人信息\n2\t购买商品\n3\t登出\n4\t更改密码\n", regexSec);
            enum class CHOICEEVENT
            {
                INFO = 1, BUY, LOGOUT,CHANGEPASS
            };
            switch ((CHOICEEVENT)choice)
            {
            case CHOICEEVENT::INFO:
                viewManger.setNext(make_unique<CustmomerView>());
                break;
            case CHOICEEVENT::BUY:
                viewManger.setNext(make_unique<BuyView>());
                break;
            case CHOICEEVENT::LOGOUT:
                viewManger.setNext(make_unique<LogoutView>());
                break;
            case CHOICEEVENT::CHANGEPASS:
                viewManger.setNext(make_unique<ChangePassView>());
             default:
                viewManger.setNext(make_unique<FailureView>());
                break;
            }
            break;
        }
        default:
            cout << "something wrong" << endl;

        }
    }
    else
    {
        cout << "用户名不存在或密码错误" << endl;
        viewManger.setNext(make_unique<FailureView>());
    }
}

bool LoginView::dealInput(string name, string pass, int choice)
{
    switch (PEOPLETYPE(choice))
    {
    case PEOPLETYPE::BUS:
        return Usr->login(name, pass);
        break;
    case PEOPLETYPE::CUS:
        return Usr->login(name, pass);
        break;
    default:
        break;
    }
}
