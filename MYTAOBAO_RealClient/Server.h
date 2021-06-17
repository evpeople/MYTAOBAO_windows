#pragma once
#include <string>
#include<iostream>
#include<unordered_map>
#include"ViewManger.h"
#include<WinSock2.h>
#include"BaseView.h"
enum class EVENT { login = 1, signUp = 2, changePassWord, showMoney, addGoods, showGoods, searchGoods, changeGoods };
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
    inline static std::unordered_map<std::string, Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string, std::vector<Json::Value>>GoodSearchFromType;
    inline static std::string GoodPath = "";
    ~Server();//�������ݡ�
    inline static SOCKET sockS;
    inline static sockaddr_in sockAdd;
private:
    static std::string Path;
    std::unique_ptr<BaseView>ptrView;
    ViewManger& viewManger = ViewManger::getInstance();

    //std::unordered_map<char, EVENT>event_map;
};