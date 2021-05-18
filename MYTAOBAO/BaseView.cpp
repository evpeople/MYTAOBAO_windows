#include "BaseView.h"
#include "Server.h"
#include<fstream>
#include<iostream>
#include <regex>
#include<random>
#include<iomanip>
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
void BaseView::input(int& choice, std::string help, std::regex regexString)
{
    cout << help << endl;

    cin >> choice;
    string temp = to_string(choice);
    if (!regex_match(temp,regexString))
    {
        cin.clear();
        cin.sync();
        input(choice,help,regexString);
    }
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
    int lenOfString = 20;
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root ,goodsOfUsr;
       
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }
        goodsOfUsr = root["goods"];
        size_t randNumber = rand()%10;
        int total = 7;
        
        cout << "名字";
        for (size_t i = randNumber; i <total+randNumber; i++)
        {
            cout<<std::left<<"\t"  <<setw(lenOfString)<< goodsOfUsr[i]["name"].asString();
        }
        cout <<endl<<"价钱";
        for (size_t i = randNumber; i <total +randNumber;i++)
        {
            cout <<std::left<< "\t" << setw(lenOfString) << goodsOfUsr[i]["price"].asDouble();
        }
        cout << endl<<"剩余量";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout<<std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["remain"].asInt64();
        }
        cout << endl<<"类型";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout <<std::left<< "\t" << setw(lenOfString) << goodsOfUsr[i]["type"].asString();
        }
        cout << endl<<"描述";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left<<"\t" << setw(lenOfString) << goodsOfUsr[i]["description"].asString();
        }
        cout << endl;

        cout << "\n\n\n\n\n\n\n" << endl;   
        fin.close();

    }
}

void BaseView::setAddress(string newLogoAddress, string newGoodsAddress)
{
    logoAddress = newLogoAddress;
    goodsAddress = newGoodsAddress;
}
