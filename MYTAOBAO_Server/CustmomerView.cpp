#include "CustmomerView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Server.h"

using namespace std;
void CustmomerView::show()
{
    showGoods();
    cout << "ÓÃ»§Ãû" << Usr->getUsrName() << endl;
    send(Server::sockS[getId()], Usr->getUsrName().c_str(), Usr->getUsrName().size(), 0);
    Usr->balance();
    Usr->storage();
    ViewManger& viewManger = ViewManger::getInstance(getId());
    viewManger.setNext(make_unique<CusResultView>());
}

void CustmomerView::viewInput()
{
}

bool CustmomerView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
