#pragma once
#include<algorithm>
#include "BaseUsr.h"
#include"shoppingCart.h"
#include<memory>
class Customer :public BaseUsr
{
public:

    Customer(std::string name, std::string PassWd);//todo:���ﳵ�ı���
    Customer(std::string name, std::string PassWd, double money);
    Customer();
    virtual void storage()override;
    virtual bool login(std::string tempUsr, std::string passWord)override;
    virtual USRTYPE getType()override;
    virtual void balance()override;
    virtual bool buySomeThing(double)override;
    virtual int getId();
    virtual bool addInShoppingCart(Json::Value&good,long long int last)override;//todo: ��ӵ����ﳵ
    virtual void minShoppingCart(Json::Value&goods, long long int last);
	virtual void showCart()override;
	virtual bool buyAllThing()override;
    virtual double calShoppingCart()override;//todo: ���㹺�ﳵ���ܼ�ֵ
    void static setAddress(std::string newAddress);
    std::string static getAddress();
    ~Customer();
private:
    long long int id;
    static USRTYPE type;
    shoppingCart shopCart;
    static long long int totalId;
    static std::string  storageAddress;
};

