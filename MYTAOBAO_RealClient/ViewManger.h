#pragma once
#include<memory>
#include"BaseView.h"

class ViewManger
{
public:
    void start();//开始工作
    void setNext(std::unique_ptr<BaseView>next);//设置下一个界面
    void sleepMs(int ms);//休眠
    static  ViewManger& getInstance();//获取单例的对象
    //{
    //    static ViewManger instance;
    //    return instance;
    //}
     //void toMain();
     //void toLogin();
     //void toLogout();
     //void toSignUp();
     //void toCustomer();
     //void toBusinessman();
     //void toFailure();
     //void toCusResult();
     //void toBusResult();
protected:

private:
    std::unique_ptr<BaseView> viewNext;
    std::unique_ptr<BaseView> viewCurrent;
    ViewManger() {};
    ~ViewManger() {};
    ViewManger(const ViewManger&);
    ViewManger& operator=(const ViewManger&);
};
