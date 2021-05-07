#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include<fstream>
#include "Customer.h"
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
        Customer::setAddress(root["usrAddress"].asString());
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
        EVENT choiceEvent = (EVENT)choice;
        cin.clear();
        cin.ignore();
        switch (choiceEvent)
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
            if (!test->login())
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
                CUSTOMERLOGIN temp = (CUSTOMERLOGIN)choice;
                cin.clear();
                cin.ignore();
                switch (temp)
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
                    BUY temp = (BUY)choice;
                    cin.clear();
                    cin.ignore();
                    switch (temp)
                    {
                    case BUY::BUY:
                        test->buySomeThing(10.00);
                        //todo: ��Ҫ��ϸ����չ
                        break;
                    case BUY::FIND:
                        //todo: ��Ҫ��ϸ����չ
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
                default:
                    in = false;
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
                        test = new Customer(usr[0], usr[1]);
                        test->storage();
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

Server::~Server()
{
}
