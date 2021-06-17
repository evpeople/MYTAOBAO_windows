#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include<fstream>
#include "Customer.h"
#include"Businessman.h"
#include"Views.h"

//todo: ÿ�δ���һ���µĽ���ʱ������һ���̣߳�Ҳ���������ڵȴ����ӽ���
//todo: �����ö��̣߳��������������飬doSomeThing
using namespace std;
string Server::Path = "config.json";
Server::Server()
{
    ifstream fin;
    fin.open(Server::Path);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }
        Businessman::setAddress(root["busmanAddress"].asString());
        Customer::setAddress(root["usrAddress"].asString());
        BaseView::setAddress(root["logoAddress"].asString(),root["goodsAddress"].asString());
        GoodPath=root["goodsAddress"].asString();
        fin.close();
    }
    else
    {
        cout << "�����ļ�������" << endl;
    }

}


void Server::start()
{
}
void Server::start(int i)
{
    viewManger.sleepMs(500);

    viewManger.setNext(make_unique<MainView>());
    viewManger.start();

}
bool Server::check(string usrId)
{
    string inPath = Customer::getAddress() + usrId + ".usr";

    ifstream fin;
    fin.open(inPath);
    if (fin.is_open())
    {
        fin.close();
        return false;
    }
    else
    {
        return true;
    }
}

void Server::loadGoods()
{

    string goodsPath = GoodPath + "defalutGoods.json";
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
            //����unordermap����ͬ���ļ�ʱ�Ḳ�����ģ����Լ���ʱ����ȷ�ġ�
            //GoodSearchFromName.insert(make_pair(name,value));
            GoodSearchFromName[name] = value;
            GoodSearchFromType[type].push_back(value);
        }
    }
}

Server::~Server()
{
}

