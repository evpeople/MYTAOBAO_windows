#pragma once
#include<string>
#include<regex>
#include<memory>


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
    virtual void show()=0 ;
    virtual void viewInput()=0  ;
    
    void showLogo();
    void showGoods();
    void static setAddress(std::string,std::string);
protected:
    virtual void input(int& choice, std::string help,std::regex regexString);
private:
    static std::string logoAddress;
    static std::string goodsAddress;

};




