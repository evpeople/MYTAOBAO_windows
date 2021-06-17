#pragma once
#include <string>
#include<vector>
#include<iostream>
#include<WinSock2.h>
#include<unordered_map>
#include"ViewManger.h"
#include"BaseView.h"
enum class EVENT { login=1, signUp=2, changePassWord, showMoney, addGoods, showGoods, searchGoods, changeGoods };
enum class LOGINEVENT { login, getIn, changePassWord, showMoney, addGoods, showGoods, searchGoods, changeGoods };
class Server
{
public:
    Server();// 初始化服务器，读取商品数据和用户数据.展示logo。
    void start();
    void start(int i);
    bool check(std::string usrId);//检查是否重复
    //开始运作
    void static loadGoods();
    void static setSockAdd(SOCKADDR tempAdd);
    void static setSocket(SOCKET tempSocket);
    inline static std::unordered_map<std::string, Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string, std::vector<Json::Value>>GoodSearchFromType;
    inline static std::string GoodPath="";
    inline static std::vector<SOCKET>sockS;
    inline static std::vector<SOCKADDR>sockAdd;
    
    ~Server();//保存数据。
private:
    static std::string Path;
    std::unique_ptr<BaseView>ptrView;
    inline static int totalid = 0;
    inline static std::vector<ViewManger>viewS;
    int id;
    //std::unordered_map<char, EVENT>event_map;
};

