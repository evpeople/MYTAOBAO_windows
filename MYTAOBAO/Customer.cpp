#include "Customer.h"
#include<json/json.h>
#include <iostream>
#include<fstream>
#include <io.h>

long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
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
    temp["usrPass"] = getUsrPassWord();//ʹ�ù�ϣ��
    temp["usrType"] = "Customer";
    temp["money"] = money;
    std::string outFile = Customer::storageAddress + getUsrName()+"usr";
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

    std::string inPath = Customer::storageAddress + "*.usr";

    std::ifstream fout;
    fout.open(inPath);
    if (fout.is_open())
    {
        Json::Reader reader;
        Json::Value root;
        if (reader.parse(fout,root))
        {
            id = root["usrID"].asInt64();
            setUsrName( root["usrName"].asString());
            setUsrPassWord(root["usrPass"].asString());
            money = root["money"].asDouble();
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
    return;
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
