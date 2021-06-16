#include "MakeBillView.h"
#include"ViewManger.h"
#include"Views.h"
#include<memory>

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
    Usr->makeBill();
    
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
            if (!Usr->buyAllThing())
            {
                cout << "���군����Ǯ�������������������ˣ���ȥ����Ǯ������";
                Usr->clearBill();
                viewManger.setNext(make_unique<CustmomerView>());
                flag = false;
                break;
            }
            Usr->clearBill();
            Usr->clearAllShopCart();
            cout << "�Ѿ�֧���˶���" << endl;
            flag = false;
            viewManger.setNext(make_unique<CartView>());
            break;
        case CHOICEEVENT::NOTBUY:
                input(choice, "���Ҫ�˳����㻹��û֧��Ŷ������8��������˳�����������������һ��ѡ��Ļ���Ŷ\n", regexFir);
                if (choice == 8)
                {
                    Usr->clearBill();
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
    // todo:�˳�ʱ ѯ�ʸ�������
    
}
