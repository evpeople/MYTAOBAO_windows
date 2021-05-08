#include "BaseView.h"
#include "Server.h"
#include<fstream>
#include<json/json.h>
using namespace std;

string BaseView::logoAddress = ".";
string BaseView::goodsAddress = ".";
void BaseView::show()
{
    //showLogo();
    showGoods();
}
void BaseView::viewInput()
{
}
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
    string goodsPath = goodsAddress + "defalutGoods.json";
    ifstream fin;
    fin.open(goodsPath);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }
        for (size_t i = 0; i < root.size(); i++)
        {
            cout << root[i]["name"].asString();
        }
        cout << endl;
        for (size_t i = 0; i < root.size(); i++)
        {
            cout << root[i]["price"].asString();
        }
        cout << endl;
        for (size_t i = 0; i < root.size(); i++)
        {
            cout << root[i]["remain"].asString();
        }
        cout << endl;
        for (size_t i = 0; i < root.size(); i++)
        {
            cout << root[i]["type"].asString();
        }
        cout << endl;
        for (size_t i = 0; i < root.size(); i++)
        {
            cout << root[i]["description"].asString();
        }
        cout << endl;


        fin.close();

    }
}

void BaseView::setAddress(string newLogoAddress, string newGoodsAddress)
{
    logoAddress = newLogoAddress;
    goodsAddress = newGoodsAddress;
}
