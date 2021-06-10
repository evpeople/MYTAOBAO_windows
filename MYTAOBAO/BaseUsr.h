#pragma once
#include <string>
#include<json/json.h>
#include"BaseGoods.h"
#include<fstream>
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
enum class USRTYPE { businessman, customer, newUsr
};
//std::ostream& operator<<(std::ostream& os, const USRTYPE& ec)
//{
//	switch (ec)
//	{
//	case USRTYPE::businessman:
//		os << "bussinessman";
//		break;
//	case USRTYPE::customer:
//		os << "customer";
//		break;
//	case USRTYPE::newUsr:
//		os << "newUsr";
//		break;
//	default:
//		break;
//	}
//
//	return os;
//}
//std::ostream& operator<<(std::ostream& os, const USRTYPE& ec)
//{
//	os << static_cast<std::underlying_type<USRTYPE>::type>(ec);
//	return os;
//}
class BaseUsr
{
public:
	BaseUsr(std::string name,std::string pd);
	virtual ~BaseUsr();
	virtual void balance();
	virtual  std::vector<std::unique_ptr<BaseGoods>>& getGoods();
	virtual bool buySomeThing(double);
	virtual void setGoods();
	virtual bool addInShoppingCart(Json::Value&good,long long int last);
    virtual void minShoppingCart(Json::Value&goods, long long int last);
	virtual void showCart();
	virtual void discount(int kind, double Discount);
	virtual bool changePassWord(std::string pass)final;
	virtual bool buyAllThing();
	virtual bool auth(std::string)final;//”…login π”√
	virtual void storage()=0;
	virtual bool login(std::string, std::string) = 0;
	virtual USRTYPE getType() = 0;
	std::string getUsrName();
	virtual double getMoney()final;
	virtual void setMoney(double newMoney)final;

    virtual double calShoppingCart();
	
	std::string tosting();
protected:
	virtual std::string encryp(const  std::string passwd)final;
	std::string getUsrPassWord();
	void setUsrName(std::string newName);
	virtual double getMoney();
	void setUsrPassWord(std::string newPassWord);

private:
    std::string usrName;
	std::string usrPassWord;
	double money;
	bool isLogin;
};
