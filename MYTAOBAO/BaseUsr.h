#pragma once
#include <string>
using namespace std;
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
	BaseUsr();
	BaseUsr(string name,string pd);
	virtual ~BaseUsr();
	void storage();
	bool auth(string);
	string encryp(const string passwd);
	string tosting();
private:
	long long int usrId;
	string usrName;
	string usrPassWord;
	USRTYPE usrType;
	bool isLogin;
	static long long int totalNum;
};
