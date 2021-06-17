#include "BaseView.h"
#include "Server.h"
#include<fstream>
#include<iostream>
#include <regex>
#include<random>
#include<iomanip>
#include<json/json.h>
#include"Server.h"
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
    if (!regex_match(temp, regexString))
    {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "\n错误的输入，请注意" << endl;
        input(choice, help, regexString);
    }
    else
    {
        send(Server::sockS, temp.c_str(), temp.length(), 0);
    }
}
void BaseView::input(std::string& choice, std::string help)
{
    cout << help << endl;
    getline(cin, choice);
    send(Server::sockS, choice.c_str(), choice.length(), 0);
}
void BaseView::input(double& num)
{
    cin >> num;
    while (!cin.good())
    {
        cout << "只能是数字" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();

        cin >> num;
    }
    string temp = to_string(num);
    send(Server::sockS, temp.c_str(), temp.length(), 0);
}

void BaseView::input(long long int& num)
{
    cin >> num;
    while (!cin.good())
    {
        cout << "只能是数字" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();

        cin >> num;
    }
    string temp = to_string(num);
    send(Server::sockS, temp.c_str(), temp.length(), 0);
}

void BaseView::input(int& num)
{
    cin >> num;
    while (!cin.good())
    {
        cout << "只能是数字" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();

        cin >> num;
    }
    string temp = to_string(num);
    send(Server::sockS, temp.c_str(), temp.length(), 0);
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

    //if (BaseView::flag == false)
    //{
    //    ofstream ofin;
    //    ofin.open(goodsPath, ios::trunc);
    //    string buffer;
    //    char a[3001];
    //    bool flag = true;

    //    while (true)
    //    {
    //        int len = recv(Server::sockS, a, 3000, 0);
    //        if (a[0] != '#')
    //        {
    //            for (size_t i = 0; i < len; i++)
    //            {
    //                if (a[i] == '#')
    //                {
    //                    recv(Server::sockS, a,1 , 0);
    //                    flag = false;
    //                    break;
    //                }
    //                ofin << a[i];
    //            }
    //            if (!flag)
    //            {
    //                break;
    //            }
    //        }
    //    }
    //    ofin.close();
    //    BaseView::flag = true;
    //}


    ifstream fin;
    fin.open(goodsPath);


    int lenOfString = 20;
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root, goodsOfUsr;

        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }
        goodsOfUsr = root["goods"];
        std::string output;
        for (Json::ValueIterator itr = goodsOfUsr.begin(); itr != goodsOfUsr.end(); itr++)
        {
            string name = (*itr)["name"].asString();
            string type = (*itr)["type"].asString();
            Json::Value value = *itr;
            //由于unordermap插入同样的键时会覆盖最后的，所以计算时是正确的。
            //GoodSearchFromName.insert(make_pair(name,value));
            GoodSearchFromName[name] = value;
            GoodSearchFromType[type].push_back(value);
        }
        //auto t=GoodSearchFromName.find("Effective C++");
       //cout <<"\n" << x.toStyledString()<<GoodSearchFromName.size();
        size_t randNumber = rand() % 10;
        char xA[50];
        int total = 7;

        cout << "名字";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["name"].asString();
        }
        cout << endl << "价钱";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["price"].asDouble();
        }
        cout << endl << "剩余量";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["remain"].asInt64();
        }
        cout << endl << "类型";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["type"].asString();
        }
        cout << endl << "描述";
        for (size_t i = randNumber; i < total + randNumber; i++)
        {
            cout << std::left << "\t" << setw(lenOfString) << goodsOfUsr[i]["description"].asString();
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