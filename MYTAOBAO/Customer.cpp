#include "Customer.h"
#include <iostream>
#include <io.h>

using namespace std;
long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
string Customer::storageAddress = ".";
Customer::Customer(string name, string PassWd)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    cout << "�����ֵ����Ǯ" << endl;
    double money;
    inputDouble(money);
    setMoney(money);
}
Customer::Customer(string name, string PassWd,double money)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    setMoney(money);
}
Customer::Customer() :BaseUsr{ "0","0" }
{
    id = 0;
    setMoney(0);
}

void Customer::storage()
{
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = id;
    temp["usrName"] = getUsrName();
    temp["usrPass"] = getUsrPassWord();
    temp["usrType"] = "Customer";
    temp["money"] = getMoney();
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
        setMoney(root["money"].asDouble());
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
    cout << "�����ڻ�ʣ" << getMoney() << "ԪǮ����ֵ������8" << endl;
    int choice;
    cin >> choice;
    if (choice == 8)
    {
        cout << "�������ֵ����Ǯ" << endl;
        double money;
        inputDouble(money);
        setMoney(getMoney() + money);
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'
        );
        return;
    }
}

bool Customer::buySomeThing(double price)
{
    if (price > getMoney())
    {
        cout << "��Ǹ�����Ǯ������" << endl;
        return false;
    }
    else
    {
        setMoney(getMoney() - price);
        cout << "�ѹ����㻹ʣ" << getMoney() << "��ô��Ǯ" << endl;
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
