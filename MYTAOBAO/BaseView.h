#pragma once
#include<string>
class BaseView 
{
    /* //todo: 一个视图类，应该只能做到视图层的交互逻辑的处理，
    最后将处理好的数据发给控制器，让控制器进行数据处理，
    之后控制器做完逻辑处理后，更改下一个类，！！！！！！！此处不由视图类操作
    所以视图类应该包含自己的控制器，不同的视图类不同的控制器，
    但所有的控制器都包含一个页面调度器
    页面调度器采用单例模式
    需要维护一个ans的string vector，最后统一传这个vector给控制器
    在show的时候，全部需要show当前的商品（就展示而言）
    */
public:
    virtual void show() = 0;
    virtual void viewInput() = 0;

    void showLogo();
    void showGoods();
    void static setAddress(std::string,std::string);

private:
    static std::string logoAddress;
    static std::string goodsAddress;

};

