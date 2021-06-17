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
    cout << "正在生产账单" << endl;
    
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
        input(choice, "1\t结账\n2\t直接退出\n", regexSec);
        cin.get();
        switch ((CHOICEEVENT)choice)
        {
        case CHOICEEVENT::BUY:
            buy();
            flag = false;
            viewManger.setNext(make_unique<CartView>());
            break;
        case CHOICEEVENT::NOTBUY:
                input(choice, "真的要退出吗，你还有没支付哦，输入8，则真的退出，其余数字则是再一次选择的机会哦\n", regexFir);
                if (choice == 8)
                {
                    flag = false;
                    break;
                }
                cout << "欢迎反悔" << endl;
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
    if (x=="钱不够，别做梦")
    {
        cout << "真完蛋，你钱不够，订单给你清零了，回去冲完钱再来吧" << endl;
    }
    else
    {
        cout << x << endl;
    }
}
