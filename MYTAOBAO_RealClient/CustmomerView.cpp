#include "CustmomerView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Server.h"

using namespace std;
void CustmomerView::show()
{
    showGoods();
    char a[80];
    int x = recv(Server::sockS, a, 30, 0);
    a[x] = '\0';
    string temp(a);
    cout << "ÓÃ»§Ãû" << temp << endl;
    send(Server::sockS, "as", 2, 0);
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