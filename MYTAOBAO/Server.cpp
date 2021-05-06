#include "Server.h"
#include <unordered_map>
#include<json/json.h>
#include "Customer.h"

Server::Server()
{
    event_map.insert(std::make_pair('a', EVENT::login));
}


void Server::start()
{
    //BaseUsr* a;
    char choice;
    std::cin >> choice;
    EVENT a;
    LOGINEVENT b;
    while (true)
    {
        switch (event_map[choice])
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
            bool in = true;
            std::cout << "����0Ϊ�鿴������Ϣ\n����1Ϊ������Ʒ";
            int choic;
            std::cin >> choic;
            
            enum{PERSONAL,GOODS};

            while (in)
            {
                switch (choic)
                {
                case PERSONAL:
                    //a.�鿴��Ϣ()
                    break;
                case GOODS:
                {
                    int choice=1;
                    std::cout << "����0Ϊ�鿴��Ʒ������1Ϊ������Ʒ������2Ϊ������Ʒ";
                    enum{SEARCH,FIND,BUY};
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
                    if (!this->check())
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
                        if (ans=="w")
                        {
                            //һ���û�����ı��档
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

bool Server::check()
{
    return false;
}

Server::~Server()
{
}
