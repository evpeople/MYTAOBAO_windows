#include "BaseView.h"
#include "Server.h"
#include<fstream>
using namespace std;

string BaseView::logoAddress = ".";
void BaseView::showLogo()
{
    system("cls");
    ifstream fstream;
    fstream.open(BaseView::logoAddress);
    if (fstream.is_open())
    {
        while (!fstream.eof())
        {
            string line;
            getline(fstream, line);
            cout << line << endl;
        }
    }
    fstream.close();
}

void BaseView::showGoods()
{
    system("cls");
    
}

void BaseView::setAddress(string newLogoAddress,string newGoodsAddress)
{
    logoAddress = newLogoAddress;
    goodsAddress = newGoodsAddress;
}
