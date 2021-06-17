#include "MakeBillView.h"
#include"ViewManger.h"
#include"Views.h"
#include<memory>
#include"Server.h"

using namespace std;
void MakeBillView::show()
{
    showGoods();
    viewInput();

}

void MakeBillView::viewInput()
{
    ViewManger& viewManger = ViewManger::getInstance();
    cout << "���������˵�" << endl;
    
    enum class CHOICEEVENT
    {
        BUY=1,NOTBUY
    };

    int choice;
    bool flag = true;

    while (flag)
    {
        std::regex regexSec("[12]");
        std::regex regexFir("^[0-9]*$");
        input(choice, "1\t����\n2\tֱ���˳�\n", regexSec);
        cin.get();
        switch ((CHOICEEVENT)choice)
        {
        case CHOICEEVENT::BUY:
            buy();
            flag = false;
            viewManger.setNext(make_unique<CartView>());
            break;
        case CHOICEEVENT::NOTBUY:
                input(choice, "���Ҫ�˳����㻹��û֧��Ŷ������8��������˳�����������������һ��ѡ��Ļ���Ŷ\n", regexFir);
                if (choice == 8)
                {
                    flag = false;
                    break;
                }
                cout << "��ӭ����" << endl;
                flag = true;
                viewManger.setNext(make_unique<CartView>());
            break;
        default:
            break;
        }
    }
   


    viewManger.sleepMs(100);
    
}

void MakeBillView::buy()
{
    char a[31];
    int len = recv(Server::sockS, a, 30, 0);
    a[len] = '\0';
    string x(a);
    if (x=="Ǯ������������")
    {
        cout << "���군����Ǯ�������������������ˣ���ȥ����Ǯ������" << endl;
    }
    else
    {
        cout << x << endl;
    }
}
