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
            //登录,判断用户类型
           /* USRTYPE：；
            switch (switch_on)
            {
            default:
                break;
            }*/
            bool in = true;
            std::cout << "输入0为查看个人信息\n输入1为购买商品";
            int choic;
            std::cin >> choic;
            
            enum{PERSONAL,GOODS};

            while (in)
            {
                switch (choic)
                {
                case PERSONAL:
                    //a.查看信息()
                    break;
                case GOODS:
                {
                    int choice=1;
                    std::cout << "输入0为查看商品，输入1为搜索商品，输入2为购买商品";
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
                    std::cout << "请输入您的用户名" << std::endl;
                    std::cin >> usr[0];
                    if (!this->check())
                    {
                        std::cout << "此用户名已被占用，请您选择其他用户名" << std::endl;
                        continue;
                    }
                    else
                    {
                        signUpJson["usrName"] = usr[0];
                        signUpEnum = NOPASSWORD;
                    }
                    [[fallthrough]];
                case NOPASSWORD:
                    std::cout << "请输入您的密码" << std::endl;
                    std::cin >> usr[1];
                    std::cout << "请再次确认您的密码" << std::endl;
                    std::cin >> usr[2];
                    if (usr[1] != usr[2])
                    {
                        std::cout << "两次密码不同，请重新注册" << std::endl;
                        continue;
                    }
                    else
                    {
                        signUpJson["usrPassWord"] = usr[1];
                        signUpEnum = NOUSRTYPE;
                    }
                    [[fallthrough]];
                case NOUSRTYPE:
                    std::cout << "请输入您的用户类型,A为顾客，B为商家" << std::endl;
                    std::cin >> usr[3];
                    if (usr[3] != "A" && usr[3] != "B")
                    {
                        std::cout << "由于您输入了错误的用户类型，请重新注册" << std::endl;
                    }
                    else
                    {
                        signUpJson["usrType"] = usr[3];
                        signUpEnum = NOUSRNAME;
                        std::cout << "您已完成了注册，详细信息如下\n" << signUpJson.toStyledString() << "\n" << "输入w保存信息，输入q重新注册" << std::endl;
                        std::string ans;
                        std::cin >> ans;
                        if (ans=="w")
                        {
                            //一个用户基类的保存。
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
