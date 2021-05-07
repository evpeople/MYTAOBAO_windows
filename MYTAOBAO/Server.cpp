#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include<fstream>
#include "Customer.h"
std::string Server::Path = "config.json";
Server::Server()
{
    std::ifstream fin;
    fin.open(Server::Path);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            std::cout << errs << std::endl;
        }
        Customer::setAddress(root["usrAddress"].asString());
        fin.close();
    }
    else
    {
        std::cout << "�����ļ�������" << std::endl;
    }

}


void Server::start()
{
    BaseUsr* test = new Customer();

    while (true)
    {
        int choice;
        std::cout << "1Ϊ��¼��2Ϊע��" << std::endl;
        std::cin >> choice;
        EVENT choiceEvent = (EVENT)choice;
        std::cin.clear();
        std::cin.ignore();
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
                std::cout << "������һ���" << std::endl;
                break;
            }
            switch (test->getType())
            {
            case USRTYPE::customer:
            {   
               bool in = true;

            while (in)
            {
                std::cout << "����0Ϊ�鿴������Ϣ\n����1Ϊ������Ʒ\n����2Ϊ�ǳ�\n";
                int choice;
                
                std::cin >> choice;
                enum class CUSTOMERLOGIN
                {
                    PERSONAL, GOODS, LOGOUT
                };
                CUSTOMERLOGIN temp = (CUSTOMERLOGIN)choice;
                std::cin.clear();
                std::cin.ignore();
                switch (temp)
                {
                case CUSTOMERLOGIN::PERSONAL:
                    test->balance();
                    break;
                case CUSTOMERLOGIN::GOODS:
                {
                    int choice;
                    std::cout << "����0Ϊ�鿴��Ʒ������1Ϊ������Ʒ������2Ϊ������Ʒ\n";
                    std::cin >> choice;
                    enum class BUY { SEARCH=0, FIND, BUY };
                    BUY temp = (BUY)choice;
                    std::cin.clear();
                    std::cin.ignore();
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
        std::string usr[4];
        while (true)
        {
            switch (signUpEnum)
            {
            case SIGNUP::NOUSRNAME:
                std::cout << "�����������û���" << std::endl;
                std::cin >> usr[0];
                if (!this->check(usr[0]))
                {
                    std::cout << "���û����ѱ�ռ�ã�����ѡ�������û���" << std::endl;
                    continue;
                }
                else
                {
                    signUpJson["usrName"] = usr[0];
                    signUpEnum = SIGNUP::NOPASSWORD;
                }
                [[fallthrough]];
            case SIGNUP::NOPASSWORD:
                std::cout << "��������������" << std::endl;
                std::cin >> usr[1];
                std::cout << "���ٴ�ȷ����������" << std::endl;
                std::cin >> usr[2];
                if (usr[1] != usr[2])
                {
                    std::cout << "�������벻ͬ��������ע��" << std::endl;
                    continue;
                }
                else
                {
                    signUpJson["usrPassWord"] = usr[1];
                    signUpEnum = SIGNUP::NOUSRTYPE;
                }
                [[fallthrough]];
            case SIGNUP::NOUSRTYPE:
                std::cout << "�����������û�����,AΪ�˿ͣ�BΪ�̼�" << std::endl;
                std::cin >> usr[3];
                if (usr[3] != "A" && usr[3] != "B")
                {
                    std::cout << "�����������˴�����û����ͣ�������ע��" << std::endl;
                }
                else
                {
                    signUpJson["usrType"] = usr[3];
                    signUpEnum = SIGNUP::NOUSRNAME;
                    std::cout << "���������ע�ᣬ��ϸ��Ϣ����\n" << signUpJson.toStyledString() << "\n" << "����w������Ϣ������q����ע��" << std::endl;
                    std::string ans;
                    std::cin >> ans;
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
bool Server::check(std::string usrId)
{
    std::string inPath = Customer::getAddress() + usrId + ".usr";

    std::ifstream fin;
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
