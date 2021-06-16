#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include<fstream>
#include "Customer.h"
#include"Businessman.h"
#include"Views.h"

//todo: 每次创建一个新的进程时，创建一个线程，也就是阻塞在等待连接建立
//todo: 不采用多线程，反而，遍历数组，doSomeThing
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
        cout << "配置文件不存在" << endl;
    }

}


void Server::start()
{
    BaseUsr* test = new Customer();

    while (true)
    {
        int choice;
        cout << "1为登录，2为注册" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
        switch ((EVENT)choice)
        {
        case EVENT::login:
        {
            //登录,判断用户类型
           /* USRTYPE：；
            switch (switch_on)
            {
            default:
                break;
            }*/
            if (!test->login("low","ss"))
            {
                cout << "再重来一遍吧" << endl;
                break;
            }
            switch (test->getType())
            {
            case USRTYPE::customer:
            {   
               bool in = true;

            while (in)
            {
                cout << "输入0为查看个人信息\n输入1为购买商品\n输入2为登出\n";
                int choice;
                
                cin >> choice;
                enum class CUSTOMERLOGIN
                {
                    PERSONAL, GOODS, LOGOUT
                };
                cin.clear();
                cin.ignore();
                switch ((CUSTOMERLOGIN)choice)
                {
                case CUSTOMERLOGIN::PERSONAL:
                    test->balance();
                    break;
                case CUSTOMERLOGIN::GOODS:
                {
                    int choice;
                    cout << "输入0为查看商品，输入1为搜索商品，输入2为购买商品\n";
                    cin >> choice;
                    enum class BUY { SEARCH=0, FIND, BUY };
                    cin.clear();
                    cin.ignore();
                    switch ((BUY)choice)
                    {
                    case BUY::BUY:
                        test->buySomeThing(10.00);
                        break;
                    case BUY::FIND:
                        break;
                    case BUY::SEARCH:
                        break;
                    default:
                        break;
                    }
                }
                break;
                case CUSTOMERLOGIN::LOGOUT:
                    in = false;
                    break;
                default:
                    in = false;
                    break;
                }
            }
            break;
            }
            case USRTYPE::businessman:
            default:
                break;
            }

        }
        break;
        case EVENT::signUp:
        {   enum class SIGNUP { NOUSRNAME, NOPASSWORD, NOUSRTYPE } signUpEnum = SIGNUP::NOUSRNAME;
        Json::Value signUpJson;
        string usr[4];
        while (true)
        {
            switch (signUpEnum)
            {
            case SIGNUP::NOUSRNAME:
                cout << "请输入您的用户名" << endl;
                cin >> usr[0];
                if (!this->check(usr[0]))
                {
                    cout << "此用户名已被占用，请您选择其他用户名" << endl;
                    continue;
                }
                else
                {
                    signUpJson["usrName"] = usr[0];
                    signUpEnum = SIGNUP::NOPASSWORD;
                }
                [[fallthrough]];
            case SIGNUP::NOPASSWORD:
                cout << "请输入您的密码" << endl;
                cin >> usr[1];
                cout << "请再次确认您的密码" << endl;
                cin >> usr[2];
                if (usr[1] != usr[2])
                {
                    cout << "两次密码不同，请重新注册" << endl;
                    continue;
                }
                else
                {
                    signUpJson["usrPassWord"] = usr[1];
                    signUpEnum = SIGNUP::NOUSRTYPE;
                }
                [[fallthrough]];
            case SIGNUP::NOUSRTYPE:
                cout << "请输入您的用户类型,A为顾客，B为商家" << endl;
                cin >> usr[3];
                if (usr[3] != "A" && usr[3] != "B")
                {
                    cout << "由于您输入了错误的用户类型，请重新注册" << endl;
                }
                else
                {
                    signUpJson["usrType"] = usr[3];
                    signUpEnum = SIGNUP::NOUSRNAME;
                    cout << "您已完成了注册，详细信息如下\n" << signUpJson.toStyledString() << "\n" << "输入w保存信息，输入q重新注册" << endl;
                    string ans;
                    cin >> ans;
                    if (ans == "w")
                    {
                        test = new Businessman(usr[0], usr[1]);
                        test->storage();
                        cout << "保存完毕" << endl;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            break;
        }
        }
        default:
            break;
        }
    }
}
void Server::start(int i)
{
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

