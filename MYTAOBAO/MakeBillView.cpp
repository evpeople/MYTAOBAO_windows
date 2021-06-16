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
    cout << "正在生产账单" << endl;
    Usr->makeBill();
    viewManger.sleepMs(100);
    viewManger.setNext(make_unique<CartView>());
    // todo:退出时 询问付不付款
    
}
