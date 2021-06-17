#include "BaseUsr.h"
#include"Server.h"
#include<iostream>
#include<fstream>
#include <openssl/sha.h>
#include<json/json.h>
#include<WinSock2.h>
using namespace std;
void BaseUsr::discount(int kind, double Discount)
{
    cout << "只有商家可以打折" << endl;
}
bool BaseUsr::changePassWord(std::string pass)
{
    usrPassWord = encryp(pass);
    this->storage();
    return true;
}
bool BaseUsr::buyAllThing()
{
    return false;
}
//long long int BaseUsr::totalNum = 0;
void BaseUsr::storage()
{
    cout << "错误的调用" << endl;
    return;
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;

    temp["usrName"] = usrName;
    temp["usrPass"] = usrPassWord;//使用哈希表！
}

void BaseUsr::makeBill()
{
}

bool BaseUsr::auth(string passwd)
{
    //unsigned char hash[SHA256_DIGEST_LENGTH];
    //SHA256_CTX sha256;
    //SHA256_Init(&sha256);
    //SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    //SHA256_Final(hash, &sha256);
    // ostringstream e;
    //for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    //{
    //    e.put(hash[i]);
    //}
    // string en_passwd = e.str();
    //return usrPassWord==en_passwd;
    string enPassWord = encryp(passwd);
    return usrPassWord == enPassWord;
}

string BaseUsr::getUsrPassWord()
{
    return usrPassWord;
}

string BaseUsr::getUsrName()
{
    return usrName;
}

void BaseUsr::clearAllShopCart()
{
}

void BaseUsr::clearBill()
{
}

double BaseUsr::calShoppingCart()
{
    return 0.0;
}

void BaseUsr::setUsrName(string newName)
{
    usrName = newName;
}

double BaseUsr::getMoney()
{
    return money;
}

void BaseUsr::setMoney(double newMoney)
{
    money = newMoney;
}

void BaseUsr::setUsrPassWord(string newPassWord)
{
    usrPassWord = newPassWord;
}

string BaseUsr::encryp(const  string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    ostringstream e;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        e << hex << (int)hash[i];
    }
    string en_passwd = e.str();
    return en_passwd;
}
//
//string BaseUsr::tosting()
//{
//    auto enumToString = [usrType=this->usrType]()->string {switch (usrType) {
//                                            case USRTYPE::customer:return "customer";
//                                            case USRTYPE::businessman:return"businessman";
//                                            case USRTYPE::newUsr: return "sd";
//
//}};
//     cout << "ID:   " << usrId << "\nName:  " << usrName << "\nType:    " << enumToString() <<"\npd"<<usrPassWord<<  endl;
//
//    return string();
//}

BaseUsr::BaseUsr(string name, string pd)
{
    usrName = name;
    usrPassWord = encryp(pd);
    isLogin = true;
}
BaseUsr::~BaseUsr()
{}

void BaseUsr::balance()
{
    cout << "只有用户用钱！！" << endl;
}

std::vector<std::unique_ptr<BaseGoods>>& BaseUsr::getGoods()
{
    std::vector<std::unique_ptr<BaseGoods>> a;
    return a;
}

bool BaseUsr::buySomeThing(double)
{
    cout << "只有用户能买东西" << endl;
    return false;
}

void BaseUsr::setGoods()
{
    cout << "只有商家能改货" << endl;
}

void BaseUsr::addGoods()
{
}

bool BaseUsr::addInShoppingCart(Json::Value& good, long long int last)
{
    return false;
}

void BaseUsr::minShoppingCart(Json::Value& goods, long long int last)
{
}

void BaseUsr::showCart()
{
}

void BaseUsr::input(double& num)
{
    cin >> num;
    while (!cin.good()||num<0)
    {
        cout << "只能是数字,且不能小于0" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();

        cin >> num;
    }
    string temp = to_string(num);
    send(Server::sockS, temp.c_str(), temp.length(), 0);
}

void BaseUsr::input(long long int& num)
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
void BaseUsr::input(int& num)
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
void BaseUsr::input(string& str)
{
    getline(cin, str);
    send(Server::sockS, str.c_str(), str.length(), 0);
}