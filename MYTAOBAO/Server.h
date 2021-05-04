#pragma once
#include <string>
#include<iostream>
using namespace std;
enum class EVENT{login,getIn,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
enum class LOGINEVENT{login,getIn,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
class Server
{
public:
    Server();
    void showSomeFile(std::string filename);
    void start();
};

