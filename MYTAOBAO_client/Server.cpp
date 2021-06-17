#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include<fstream>
#include "Customer.h"
#include"Businessman.h"
#include"Views.h"
#include <mutex>


//todo: 每次创建一个新的进程时，创建一个线程，也就是阻塞在等待连接建立
//todo: 不采用多线程，反而，遍历数组，doSomeThing
using namespace std;
static mutex exclusive2;
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
        cout << "配置文件不存在" << endl;
    }

}


void Server::start()
{}
void Server::start(int i)
{
    exclusive2.lock();
    id = totalid;
    totalid++;
    ViewManger& viewOne= ViewManger::getInstance(id);
    viewS.push_back(viewOne);
    //viewManger.setId(id);
    viewOne.sleepMs(200);
    std::unique_ptr<BaseView> View = make_unique<MainView>();
    viewOne.setId(id);
    View->setId(id);
    viewOne.setNow(std::move(View));
    std::unique_ptr<BaseView> View2 = make_unique<MainView>();
    View2->setId(id);
    viewOne.setNext(std::move(View2));
    exclusive2.unlock();
    viewOne.start();

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
            //由于unordermap插入同样的键时会覆盖最后的，所以计算时是正确的。
            //GoodSearchFromName.insert(make_pair(name,value));
            GoodSearchFromName[name] = value;
            GoodSearchFromType[type].push_back(value);
        }
    }
}

void Server::setSockAdd(SOCKADDR tempAddr)
{
    sockAdd.push_back(tempAddr);
}

void Server::setSocket(SOCKET tempSocket)
{
    sockS.push_back(tempSocket);
}

Server::~Server()
{
}

