#pragma once
#include<memory>
#include"BaseView.h"

class ViewManger
{
public:
    void start();
    void setNext(std::unique_ptr<BaseView>next);
    void sleepMs(int ms);
    static  ViewManger& getInstance();
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
