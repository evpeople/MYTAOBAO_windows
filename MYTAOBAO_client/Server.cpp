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
    BaseUsr* test = new Customer();

    while (true)
    {
        int choice;
        cout << "1Ϊ��¼��2Ϊע��" << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
        switch ((EVENT)choice)
        {
        case EVENT::login:
        {
            //��¼,�ж��û�����
           /* USRTYPE����
            switch (switch_on)
            {
            default:
                break;
            }*/
            if (!test->login("low","ss"))
            {
                cout << "������һ���" << endl;
                break;
            }
            switch (test->getType())
            {
            case USRTYPE::customer:
            {   
               bool in = true;

            while (in)
            {
                cout << "����0Ϊ�鿴������Ϣ\n����1Ϊ������Ʒ\n����2Ϊ�ǳ�\n";
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
                    cout << "����0Ϊ�鿴��Ʒ������1Ϊ������Ʒ������2Ϊ������Ʒ\n";
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
                cout << "�����������û���" << endl;
                cin >> usr[0];
                if (!this->check(usr[0]))
                {
                    cout << "���û����ѱ�ռ�ã�����ѡ�������û���" << endl;
                    continue;
                }
                else
                {
                    signUpJson["usrName"] = usr[0];
                    signUpEnum = SIGNUP::NOPASSWORD;
                }
                [[fallthrough]];
            case SIGNUP::NOPASSWORD:
                cout << "��������������" << endl;
                cin >> usr[1];
                cout << "���ٴ�ȷ����������" << endl;
                cin >> usr[2];
                if (usr[1] != usr[2])
                {
                    cout << "�������벻ͬ��������ע��" << endl;
                    continue;
                }
                else
                {
                    signUpJson["usrPassWord"] = usr[1];
                    signUpEnum = SIGNUP::NOUSRTYPE;
                }
                [[fallthrough]];
            case SIGNUP::NOUSRTYPE:
                cout << "�����������û�����,AΪ�˿ͣ�BΪ�̼�" << endl;
                cin >> usr[3];
                if (usr[3] != "A" && usr[3] != "B")
                {
                    cout << "�����������˴�����û����ͣ�������ע��" << endl;
                }
                else
                {
                    signUpJson["usrType"] = usr[3];
                    signUpEnum = SIGNUP::NOUSRNAME;
                    cout << "���������ע�ᣬ��ϸ��Ϣ����\n" << signUpJson.toStyledString() << "\n" << "����w������Ϣ������q����ע��" << endl;
                    string ans;
                    cin >> ans;
                    if (ans == "w")
                    {
                        test = new Businessman(usr[0], usr[1]);
                        test->storage();
                        cout << "�������" << endl;
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
            //����unordermap����ͬ���ļ�ʱ�Ḳ�����ģ����Լ���ʱ����ȷ�ġ�
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

