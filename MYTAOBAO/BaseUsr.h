#pragma once
#include <string>
#include<json/json.h>
#include"BaseGoods.h"
#include<fstream>
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
	virtual void addGoods();
	virtual  std::vector<std::unique_ptr<BaseGoods>>& getGoods();
	virtual bool buySomeThing(double);
	virtual void setGoods();
	virtual void discount(int kind, double Discount);
	virtual bool changePassWord(std::string pass)final;
	virtual bool auth(std::string)final;//”…login π”√
	virtual void storage()=0;
	virtual bool login(std::string, std::string) = 0;
	virtual USRTYPE getType() = 0;
	std::string getUsrName();

	
	std::string tosting();
protected:
	virtual std::string encryp(const  std::string passwd)final;
	std::string getUsrPassWord();
	void setUsrName(std::string newName);
	void setUsrPassWord(std::string newPassWord);
	void inputDouble(double& num);
	void inputLLint(long long int& num);
	virtual double getMoney()final;
	virtual void setMoney(double newMoney)final;

private:
    std::string usrName;
	std::string usrPassWord;
	double money;
	bool isLogin;
};
