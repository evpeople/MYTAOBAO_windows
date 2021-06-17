#pragma once
#include<algorithm>
#include "BaseUsr.h"
#include"shoppingCart.h"
#include<memory>
class Customer :public BaseUsr
{
public:

    Customer(std::string name, std::string PassWd);
    Customer(std::string name, std::string PassWd, double money);
    Customer();
    virtual void storage()override;
    virtual bool login(std::string tempUsr, std::string passWord)override;
    virtual USRTYPE getType()override;
    virtual void balance()override;
    virtual bool buySomeThing(double)override;
    virtual long long int getId();
    virtual bool addInShoppingCart(Json::Value& good, long long int last)override;
    virtual void minShoppingCart(Json::Value& goods, long long int last);
    virtual void showCart()override;
    virtual void makeBill()override;
    virtual bool buyAllThing()override;
    virtual double calShoppingCart()override;
    void static setAddress(std::string newAddress);
    virtual void clearAllShopCart()override;
    virtual void clearBill()override;
    std::string static getAddress();
    ~Customer();
private:
    long long int id;
    static USRTYPE type;
    shoppingCart shopCart;
    static long long int totalId;
    static std::string  storageAddress;
};
