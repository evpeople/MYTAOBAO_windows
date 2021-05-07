#include "Customer.h"
#include<json/json.h>
#include <iostream>
#include<fstream>
#include <io.h>

long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
std::string Customer::storageAddress = "as";
Customer::Customer(std::string name, std::string PassWd):BaseUsr{ name, PassWd
}
{
    id = totalId;
    totalId++;

    std::cout << "�����ֵ����Ǯ" << std::endl;
    std::cin >> money;
}

Customer::Customer():BaseUsr{"defalut","0"}
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
    std::string outFile = Customer::storageAddress + getUsrName()+".usr";
    std::ofstream fout{outFile ,std::ios_base::app };
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp, &fout);
    fout.close();
}

bool Customer::login()
{
    std::cout << "�����������û���" << std::endl;
    std::string tempUsr;
    std::cin >> tempUsr;

    std::string inPath = Customer::storageAddress + tempUsr+".usr";

    std::ifstream fin;
    fin.open(inPath);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            std::cout << errs << std::endl;
        }

            id = root["usrID"].asInt64();
            setUsrName( root["usrName"].asString());
            setUsrPassWord(root["usrPass"].asString());
            money = root["money"].asDouble();
        fin.close();
        std::cout << "��������������" << std::endl;
        std::string passWord;
        std::cin >> passWord;
        //passWord = "evp";
        if (auth(passWord))
        {
            std::cout << "��½�ɹ�" << std::endl;
            return true;
        }
        else
        {
            std::cout << "�������" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "��Ǹ�����û������ڣ�����ע��" << std::endl;
    }
    return false;
}

USRTYPE Customer::getType()
{
    return Customer::type;
}

void Customer::balance()
{
    std::cout << "�����ڻ�ʣ" << money << "ԪǮ����ֵ������8" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice==8)
    {
        std::cout << "�������ֵ����Ǯ" << std::endl;
        std::cin >> choice;
        money += choice;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore();
        return;
    }
}

void Customer::buySomeThing(double price)
{
    if (price>money)
    {
        std::cout << "��Ǹ�����Ǯ������" << std::endl;
    }
    else
    {
        money -= price;
        std::cout << "�ѹ����㻹ʣ" << money << "��ô��Ǯ" << std::endl;
    }
}

int Customer::getId()
{
    return id;
}

void Customer::setAddress(std::string newAddress)
{
    Customer::storageAddress = newAddress;
}

std::string Customer::getAddress()
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
