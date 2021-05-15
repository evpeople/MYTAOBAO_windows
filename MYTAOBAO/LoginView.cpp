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
    input(choice, "1\t��������ݵ�¼\n2\t�Թ˿���ݵ�¼\n", regexFir);
    std::cout << "�������û���" << endl;
    cin >> name;
    cout << "����������" << endl;
    cin >> password;
    if (dealInput(name, password, choice))
    {
        switch ((PEOPLETYPE)choice)
        {
            //���ˣ���
        case PEOPLETYPE::BUS:
        {   input(choice, "�𾴵��̼�\n1\t������Ʒ\n2\t����\n3\t�ǳ�\n4\t��������\n", regexSec);
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
        //�˿ͣ���
        }
        case PEOPLETYPE::CUS:
        {
            input(choice, "�𾴵Ŀ���\n1\t�鿴������Ϣ\n2\t������Ʒ\n3\t�ǳ�\n4\t��������\n", regexSec);
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
        cout << "�û��������ڻ��������" << endl;
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
