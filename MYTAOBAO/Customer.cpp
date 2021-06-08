#include "Customer.h"
#include <iostream>
#include <io.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios_base;
long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
string Customer::storageAddress = ".";
Customer::Customer(string name, string PassWd)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    cout << "�����ֵ����Ǯ" << endl;
    cin >> money;
}
Customer::Customer(string name, string PassWd,double money)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    this->money= money;
}
Customer::Customer() :BaseUsr{ "0","0" }
{
    id = 0;
    money = 0;
}

void Customer::storage()
{
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = id;
    temp["usrName"] = getUsrName();
    temp["usrPass"] = getUsrPassWord();
    temp["usrType"] = "Customer";
    temp["money"] = money;
    string outFile = Customer::storageAddress + getUsrName() + ".usr";
    ofstream fout{ outFile ,ios_base::out};
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp, &fout);
    fout.close();
}

bool Customer::login(string tempUsr,string passWord)
{

    string inPath = Customer::storageAddress + tempUsr + ".usr";

    ifstream fin;
    fin.open(inPath);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }

        id = root["usrID"].asInt64();
        setUsrName(root["usrName"].asString());
        setUsrPassWord(root["usrPass"].asString());
        money = root["money"].asDouble();
        fin.close();
        //passWord = "evp";
        if (auth(passWord))
        {
            cout << "��½�ɹ�" << endl;
            return true;
        }
        else
        {
            cout << "�������" << endl;
            return false;
        }
    }
    else
    {
        cout << "��Ǹ�����û������ڣ�����ע��" << endl;
    }
    return false;
}

USRTYPE Customer::getType()
{
    return Customer::type;
}

void Customer::balance()
{
    cout << "�����ڻ�ʣ" << money << "ԪǮ����ֵ������8" << endl;
    int choice;
    cin >> choice;
    if (choice == 8)
    {
        cout << "�������ֵ����Ǯ" << endl;
        cin >> choice;
        money += choice;
    }
    else
    {
        cin.clear();
        cin.ignore();
        return;
    }
}

bool Customer::buySomeThing(double price)
{
    if (price > money)
    {
        cout << "��Ǹ�����Ǯ������" << endl;
        return false;
    }
    else
    {
        money -= price;
        cout << "�ѹ����㻹ʣ" << money << "��ô��Ǯ" << endl;
        return true;
    }
}

int Customer::getId()
{
    return id;
}

void Customer::setAddress(string newAddress)
{
    Customer::storageAddress = newAddress;
}

string Customer::getAddress()
{
    return Customer::storageAddress;
}

//_finddata_t fileInfo;
//long handle = _findfirst(inPath.c_str(), &fileInfo);
//if (handle==-1)//todo: �쳣����
//{
//    std::cout << "��ʱ��û���ļ�" << std::endl;
//    return false;
//}
//int finded = 0;
//do
//{
//    if ((tempUsr+".usr")==fileInfo.name)
//    {
//        finded = 1;
//        break;
//    }
//} while (!_findnext(handle,&fileInfo);
//_findclose(handle);

Customer::~Customer()
{
    int a = 1;
}
