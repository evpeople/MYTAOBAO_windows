#pragma once
#include <string>
#include<json/json.h>
#include"BaseGoods.h"
#include<fstream>
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
enum class USRTYPE {
    businessman, customer, newUsr
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
    BaseUsr(std::string name, std::string pd);
    virtual ~BaseUsr();
    virtual void balance(); //用户购物
    virtual  std::vector<std::unique_ptr<BaseGoods>>& getGoods(); //获取商品列表
    virtual bool buySomeThing(double);//早期的购买
    virtual void setGoods();//设定商品
    virtual void addGoods();//添加商品
    virtual bool addInShoppingCart(Json::Value& good, long long int last);//往购物车中添加商品
    virtual void minShoppingCart(Json::Value& goods, long long int last);//在购物车中减少商品
    virtual void showCart();//展示购物车
    virtual void discount(int kind, double Discount);//打折
    virtual bool changePassWord(std::string pass)final;//改密码
    virtual bool buyAllThing();//清空购物车，全买了
    virtual bool auth(std::string)final;//由login使用
    virtual void storage() = 0;//存储
    virtual bool login(std::string, std::string) = 0;//登录
    virtual void makeBill();//制作账单
    virtual USRTYPE getType() = 0;//获取用户类型
    std::string getUsrName();//获取用户名字
    virtual void clearAllShopCart();//清空购物车，不付费
    virtual void clearBill();//清空账单，解除冻结

    virtual void setMoney(double newMoney)final;//设置钱
    virtual double getMoney()final;//得到当前用户拥有的钱
    virtual double calShoppingCart();//计算购物车的总价值

protected:
    void input(double& num);//多种输入函数
    void input(long long int& num);
    void input(int& num);
    void input(std::string& str);
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
