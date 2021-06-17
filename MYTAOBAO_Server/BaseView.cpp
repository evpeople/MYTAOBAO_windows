#include "BaseView.h"
#include "Server.h"
#include<fstream>
#include<iostream>
#include <regex>
#include<random>
#include<iomanip>
#include<json/json.h>
constexpr auto lenOfOneNumber = 1;
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
int BaseView::getId()
{
    return id;
}
void BaseView::setId(int id)
{
    this->id = id;
}
void BaseView::input(int& choice, std::string help, std::regex regexString)
{
    cout << help << endl;
    //send(Server::sockS[getId()], help.c_str(), help.length(), 0);
    char  a[lenOfOneNumber];
    int temp = recv(Server::sockS[getId()], a, lenOfOneNumber,0 );
    choice = a[0] - '0';
}
void BaseView::input(std::string& choice, std::string help)
{
    cout << help << endl;
    char a[101];
    signed long size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);
    while (size==-1)
    {
       size = recv(Server::sockS[getId()], a, 100, MSG_PEEK );

    }
    int x = recv(Server::sockS[getId()], a, size, 0);
    a[x] = '\0';
    string str(a);
    choice = str;
    cout << choice << endl;
    //getline(cin,choice);
}
void BaseView::input(double& num)
{
    char a[100];
    char* endptr;
    signed long size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);
    while (size == -1)
    {
        size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);

    }
    int x = recv(Server::sockS[getId()], a, size, 0);
    num = strtod(a, &endptr);
}


void BaseView::input(long long int& num)
{
    char a[100];
    char* endptr;
    signed long size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);
    while (size == -1)
    {
        size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);

    }
    int x = recv(Server::sockS[getId()], a, size, 0);
    num = strtol(a, &endptr,0);
}

void BaseView::input(int& num)
{

    char a[100];
    char* endptr;
    signed long size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);
    while (size == -1)
    {
        size = recv(Server::sockS[getId()], a, 100, MSG_PEEK);

    }
    int x = recv(Server::sockS[getId()], a, size, 0);
    num = strtol(a, &endptr, 0);
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
        std::string output;
        for (Json::ValueIterator itr = goodsOfUsr.begin(); itr != goodsOfUsr.end(); itr++)
        {
            string name=(*itr)["name"].asString();
            string type = (*itr)["type"].asString();
            Json::Value value=*itr;
            //由于unordermap插入同样的键时会覆盖最后的，所以计算时是正确的。
            //GoodSearchFromName.insert(make_pair(name,value));
            GoodSearchFromName[name] = value;
            GoodSearchFromType[type].push_back(value);
        }
        //auto t=GoodSearchFromName.find("Effective C++");
       //cout <<"\n" << x.toStyledString()<<GoodSearchFromName.size();
       size_t randNumber = rand() % 10;
       send(Server::sockS[getId()], to_string(randNumber).c_str(), to_string(randNumber).size(), 0);
        int total = 7;
        
        cout << "名字";
        for (size_t i = randNumber; i <total+randNumber; i++)
        {
            send(Server::sockS[getId()], goodsOfUsr[i]["name"].asString().c_str(), goodsOfUsr[i]["name"].asString().size(), 0);
            cout<<std::left<<"\t"  <<setw(lenOfString)<< goodsOfUsr[i]["name"].asString();
        }
        cout <<endl<<"价钱";
        for (size_t i = randNumber; i <total +randNumber;i++)
        {
            send(Server::sockS[getId()], goodsOfUsr[i]["price"].asString().c_str(), goodsOfUsr[i]["price"].asString().size(), 0);
            cout <<std::left<< "\t" << setw(lenOfString) << goodsOfUsr[i]["price"].asDouble();
        }
        cout << endl<<"剩余量";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            send(Server::sockS[getId()], goodsOfUsr[i]["remain"].asString().c_str(), goodsOfUsr[i]["remain"].asString().size(), 0);
            cout<<std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["remain"].asInt64();
        }
        cout << endl<<"类型";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            send(Server::sockS[getId()], goodsOfUsr[i]["type"].asString().c_str(), goodsOfUsr[i]["type"].asString().size(), 0);
            cout <<std::left<< "\t" << setw(lenOfString) << goodsOfUsr[i]["type"].asString();
        }
        cout << endl<<"描述";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            send(Server::sockS[getId()], goodsOfUsr[i]["description"].asString().c_str(), goodsOfUsr[i]["description"].asString().size(), 0);
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
