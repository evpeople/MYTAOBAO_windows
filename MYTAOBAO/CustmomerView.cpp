#include "CustmomerView.h"
#include"ViewManger.h"
#include"Views.h"

using namespace std;
void CustmomerView::show()
{
    showGoods();
    cout << "ÓÃ»§Ãû" << Usr->getUsrName() << endl;
    Usr->balance();
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
