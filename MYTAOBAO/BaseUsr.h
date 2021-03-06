#pragma once
#include <string>
#include<json/json.h>
#include"BaseGoods.h"
#include<fstream>
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
enum class USRTYPE {
    businessman, customer, newUsr
};
class BaseUsr
{
public:
    BaseUsr(std::string name, std::string pd);
    virtual ~BaseUsr();
    virtual void balance();
    virtual  std::vector<std::unique_ptr<BaseGoods>>& getGoods();
    virtual bool buySomeThing(double);
    virtual void setGoods();
    virtual void addGoods();
    virtual bool addInShoppingCart(Json::Value& good, long long int last);
    virtual void minShoppingCart(Json::Value& goods, long long int last);
    virtual void showCart();
    virtual void discount(int kind, double Discount);
    virtual bool changePassWord(std::string pass)final;
    virtual bool buyAllThing();
    virtual bool auth(std::string)final;//??loginʹ??
    virtual void storage() = 0;
    virtual bool login(std::string, std::string) = 0;
    virtual void makeBill();
    virtual USRTYPE getType() = 0;
    std::string getUsrName();
    virtual void clearAllShopCart();
    virtual void clearBill();

    virtual void setMoney(double newMoney)final;
    virtual double getMoney()final;
    virtual double calShoppingCart();

protected:
    void inputDouble(double& num);
    void inputLLint(long long int& num);
    virtual std::string encryp(const  std::string passwd)final;
    std::string getUsrPassWord();
    void setUsrName(std::string newName);
    void setUsrPassWord(std::string newPassWord);

private:
    std::string usrName;
    std::string usrPassWord;
    double money;
    bool isLogin;
};
