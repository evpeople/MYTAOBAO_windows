#pragma once
#include <string>
#include<iostream>
#include<unordered_map>
enum class EVENT{login,signUp,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
enum class LOGINEVENT{login,getIn,changePassWord,showMoney,addGoods,showGoods,searchGoods,changeGoods};
class Server
{
public:
    Server();//��ʼ������������ȡ��Ʒ���ݺ��û�����.չʾlogo��
    void start();//��ʼ����
    bool check();//����û����Ƿ��ظ���
    ~Server();//�������ݡ�
private:
        
	std::unordered_map<char, EVENT>event_map;
};

