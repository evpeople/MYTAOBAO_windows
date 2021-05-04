#pragma once
#include <string>
using namespace std;
enum class EVENT{login,getIn,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
class Server
{
public:
    Server();
    void showSomeFile(std::string filename);

};

