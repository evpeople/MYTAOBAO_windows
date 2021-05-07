#pragma once
#include <string>
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
	virtual void getGoods();
	virtual void buySomeThing(double);
	virtual void setGoods();
	virtual void discount();
	virtual bool changePassWord()final;

	virtual void storage()=0;
	virtual bool login() = 0;
	virtual USRTYPE getType() = 0;

	
	std::string tosting();
protected:
	virtual std::string encryp(const  std::string passwd)final;
	virtual bool auth(std::string)final;//”…login π”√
	std::string getUsrPassWord();
	std::string getUsrName();
	void setUsrName(std::string newName);
	void setUsrPassWord(std::string newPassWord);

private:
    std::string usrName;
	std::string usrPassWord;
	bool isLogin;
};
