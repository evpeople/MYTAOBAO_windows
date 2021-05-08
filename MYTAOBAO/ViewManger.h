#pragma once
#include"BaseView.h"
#include<memory>
class ViewManger
{
public:
    void start();
    void setNext(std::unique_ptr<BaseView>next);
    //void toMain();
    //void toLogin();
    //void toLogout();
    //void toSignUp();
    //void toCustomer();
    //void toBusinessman();
    //void toFailure();
    //void toCusResult();
    //void toBusResult();
private:
    std::unique_ptr<BaseView> viewNext;
    std::unique_ptr<BaseView> viewCurrent;
};

