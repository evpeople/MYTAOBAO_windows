#pragma once
#include <string>
#include<iostream>
#include<unordered_map>
enum class EVENT { login=1, signUp=2, changePassWord, showMoney, addGoods, showGoods, searchGoods, changeGoods };
enum class LOGINEVENT { login, getIn, changePassWord, showMoney, addGoods, showGoods, searchGoods, changeGoods };
class Server
{
public:
    Server();//��ʼ������������ȡ��Ʒ���ݺ��û�����.չʾlogo��
    void start();
    bool check(std::string usrId);//����Ƿ��ظ�
    //��ʼ����
    ~Server();//�������ݡ�
private:
    static std::string Path;
	//std::unordered_map<char, EVENT>event_map;
};

