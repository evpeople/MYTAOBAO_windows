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
    int lenOfString = 20;

    char b[31];
    int lenB=recv(Server::sockS, b, 30, 0);
    b[lenB] = '\0';
    string x(b);
    int randNumber = strtol(x.c_str(), nullptr,0);
    int total = 7;

    cout << "名字";
    char a[301];
    int len;
    for (size_t i = randNumber; i < total + randNumber; i++)
    {
        len=recv(Server::sockS, a, 300, 0);
        a[len] = '\0';
        string x(a);
        cout << std::left << "\t" << setw(lenOfString) << x;
    }
    cout << endl << "价钱";
    for (size_t i = randNumber; i < total + randNumber; i++)
    {
        len = recv(Server::sockS, a, 300, 0);
        a[len] = '\0';
        string x(a);
        cout << std::left << "\t" << setw(lenOfString) << x;
    }
    cout << endl << "剩余量";
    for (size_t i = randNumber; i < total + randNumber; i++)
    {
        len = recv(Server::sockS, a, 300, 0);
        a[len] = '\0';
        string x(a);
        cout << std::left << "\t" << setw(lenOfString) << x;
    }
    cout << endl << "类型";
    for (size_t i = randNumber; i < total + randNumber; i++)
    {
        len = recv(Server::sockS, a, 300, 0);
        a[len] = '\0';
        string x(a);
        cout << std::left << "\t" << setw(lenOfString) << x;
    }
    cout << endl << "描述";
    for (size_t i = randNumber; i < total + randNumber; i++)
    {
        len = recv(Server::sockS, a, 300, 0);
        a[len] = '\0';
        string x(a);
        cout << std::left << "\t" << setw(lenOfString) << x;
    }
    cout << endl;

    cout << "\n\n\n\n\n\n\n" << endl;

}

void BaseView::setAddress(string newLogoAddress, string newGoodsAddress)
{
    logoAddress = newLogoAddress;
    goodsAddress = newGoodsAddress;
}
