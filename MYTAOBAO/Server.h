#pragma once
#include <string>
#include<iostream>
#include<unordered_map>
enum class EVENT{login,signUp,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
enum class LOGINEVENT{login,getIn,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
class Server
{
public:
    Server();//初始化服务器，读取商品数据和用户数据.展示logo。
    void start();//开始运作
    bool check();//检查用户名是否重复。
    ~Server();//保存数据。
private:
        
	std::unordered_map<char, EVENT>event_map;
};

