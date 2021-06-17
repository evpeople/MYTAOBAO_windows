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
    Server();// ��ʼ������������ȡ��Ʒ���ݺ��û�����.չʾlogo��
    void start();
    void start(int i);
    bool check(std::string usrId);//����Ƿ��ظ�
    //��ʼ����
    void static loadGoods();
    void static setSockAdd(SOCKADDR tempAdd);
    void static setSocket(SOCKET tempSocket);
    inline static std::unordered_map<std::string, Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string, std::vector<Json::Value>>GoodSearchFromType;
    inline static std::string GoodPath="";
    inline static std::vector<SOCKET>sockS;
    inline static std::vector<SOCKADDR>sockAdd;
    
    ~Server();//�������ݡ�
private:
    static std::string Path;
    std::unique_ptr<BaseView>ptrView;
    inline static int totalid = 0;
    inline static std::vector<ViewManger>viewS;
    int id;
    //std::unordered_map<char, EVENT>event_map;
};

