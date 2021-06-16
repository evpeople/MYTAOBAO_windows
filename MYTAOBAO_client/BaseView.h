#pragma once
#include<string>
#include<regex>
#include<memory>
#include"Businessman.h"
#include"Customer.h"

class BaseView 
{
    /*
    最后将处理好的数据发给控制器，让控制器进行数据处理，
    之后控制器做完逻辑处理后，更改下一个类，！！！！！！！此处不由视图类操作
    所以视图类应该包含自己的控制器，不同的视图类不同的控制器，
    但所有的控制器都包含一个页面调度器
    页面调度器采用单例模式
    需要维护一个ans的string vector，最后统一传这个vector给控制器
    在show的时候，全部需要show当前的商品（就展示而言）
    */
public:
    virtual void show() ;
    virtual void viewInput()  ;
    
    int getId();
    void setId(int id);
    void showLogo();
    void showGoods();
    void static setAddress(std::string,std::string);
protected:
    int id;
    virtual void input(int& choice, std::string help,std::regex regexString);
    virtual void input(std::string& choice, std::string help);
    static void input(double& num);
    static void input(long long int& num);
    static  void input(int& k);

    //std::unique_ptr<Businessman>Bus(new Businessman()) ;
    inline static std::unique_ptr<BaseUsr> Usr = nullptr;
    inline static std::unordered_map<std::string,Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string,std::vector<Json::Value>>GoodSearchFromType;
    //inline static std::unique_ptr<Businessman> Bus{ std::make_unique<Businessman>() };//出问题是是这个static
    //inline static std::unique_ptr<Customer>Cus{ std::make_unique<Customer>() };
private:
    static std::string logoAddress;
    static std::string goodsAddress;
    
};




