#include "CustmomerView.h"
#include"ViewManger.h"
#include"Views.h"

using namespace std;
void CustmomerView::show()
{
    showGoods();
    cout << "�û���" << Usr->getUsrName() << endl;
    Usr->balance();
    Usr->storage();
    ViewManger& viewManger = ViewManger::getInstance();
    viewManger.setNext(make_unique<CusResultView>());
}

void CustmomerView::viewInput()
{
}

bool CustmomerView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
