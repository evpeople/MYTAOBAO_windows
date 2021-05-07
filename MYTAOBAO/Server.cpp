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
        std::cout << "配置文件不存在" << std::endl;
    }

}


void Server::start()
{
    BaseUsr* test = new Customer();

    while (true)
    {
        int choice;
        std::cout << "1为登录，2为注册" << std::endl;
        std::cin >> choice;
        EVENT choiceEvent = (EVENT)choice;
        std::cin.clear();
        std::cin.ignore();
        switch (choiceEvent)
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
            if (!test->login())
            {
                std::cout << "再重来一遍吧" << std::endl;
                break;
            }
            switch (test->getType())
            {
            case USRTYPE::customer:
            {   
               bool in = true;

            while (in)
            {
                std::cout << "输入0为查看个人信息\n输入1为购买商品\n输入2为登出\n";
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
                    std::cout << "输入0为查看商品，输入1为搜索商品，输入2为购买商品\n";
                    std::cin >> choice;
                    enum class BUY { SEARCH=0, FIND, BUY };
                    BUY temp = (BUY)choice;
                    std::cin.clear();
                    std::cin.ignore();
                    switch (temp)
                    {
                    case BUY::BUY:
                        test->buySomeThing(10.00);
                        //todo: 需要详细的拓展
                        break;
                    case BUY::FIND:
                        //todo: 需要详细的拓展
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
                std::cout << "请输入您的用户名" << std::endl;
                std::cin >> usr[0];
                if (!this->check(usr[0]))
                {
                    std::cout << "此用户名已被占用，请您选择其他用户名" << std::endl;
                    continue;
                }
                else
                {
                    signUpJson["usrName"] = usr[0];
                    signUpEnum = SIGNUP::NOPASSWORD;
                }
                [[fallthrough]];
            case SIGNUP::NOPASSWORD:
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
                    signUpEnum = SIGNUP::NOUSRTYPE;
                }
                [[fallthrough]];
            case SIGNUP::NOUSRTYPE:
                std::cout << "请输入您的用户类型,A为顾客，B为商家" << std::endl;
                std::cin >> usr[3];
                if (usr[3] != "A" && usr[3] != "B")
                {
                    std::cout << "由于您输入了错误的用户类型，请重新注册" << std::endl;
                }
                else
                {
                    signUpJson["usrType"] = usr[3];
                    signUpEnum = SIGNUP::NOUSRNAME;
                    std::cout << "您已完成了注册，详细信息如下\n" << signUpJson.toStyledString() << "\n" << "输入w保存信息，输入q重新注册" << std::endl;
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
