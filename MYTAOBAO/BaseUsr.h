#pragma once
#include <string>
using namespace std;
enum usrType { businessman, customer, newUsr };
class BaseUsr
{
public:
	BaseUsr();
	virtual ~BaseUsr();
	void storage();
	string encryp(string);
private:
	long long int usrId;
	string usrName;
	string usrPassWord;
	usrType newUsr;
	bool isLogin;
	string
};

BaseUsr::BaseUsr()
{
}

inline BaseUsr::~BaseUsr()
{
}