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
        if (!Json::parseFromStream(reader,fin,&root,&errs))
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
    int choice;
    std::cout << "1Ϊ��¼��2Ϊע��" << std::endl;
    std::cin >> choice;
    EVENT choiceEvent = (EVENT)choice;
    while (true)
    {
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
            test->login();
            bool in = true;
            std::cout << "����0Ϊ�鿴������Ϣ\n����1Ϊ������Ʒ";
            int choic;
            std::cin >> choic;

            enum { PERSONAL, GOODS };

            while (in)
            {
                switch (choic)
                {
                case PERSONAL:
                    //a.�鿴��Ϣ()
                    break;
                case GOODS:
                {
                    int choice = 1;
                    std::cout << "����0Ϊ�鿴��Ʒ������1Ϊ������Ʒ������2Ϊ������Ʒ";
                    enum { SEARCH, FIND, BUY };
                    switch (choice)
                    {
                    default:
                        break;
                    }
                }
                break;
                default:
                    in = false;
                }
            }
        }
        break;
        case EVENT::signUp:
        {   enum { NOUSRNAME, NOPASSWORD, NOUSRTYPE } signUpEnum = NOUSRNAME;
        Json::Value signUpJson;
        std::string usr[4];
        while (true)
        {
            switch (signUpEnum)
            {
            case NOUSRNAME:
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
                    signUpEnum = NOPASSWORD;
                }
                [[fallthrough]];
            case NOPASSWORD:
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
                    signUpEnum = NOUSRTYPE;
                }
                [[fallthrough]];
            case NOUSRTYPE:
                std::cout << "�����������û�����,AΪ�˿ͣ�BΪ�̼�" << std::endl;
                std::cin >> usr[3];
                if (usr[3] != "A" && usr[3] != "B")
                {
                    std::cout << "�����������˴�����û����ͣ�������ע��" << std::endl;
                }
                else
                {
                    signUpJson["usrType"] = usr[3];
                    signUpEnum = NOUSRNAME;
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


            break;
        }
    }
}

bool Server::check(std::string usrId)
{
    std::string inPath = Customer::getAddress()+ usrId + ".usr";

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
