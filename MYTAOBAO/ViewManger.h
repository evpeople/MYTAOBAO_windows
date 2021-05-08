#pragma once
#include"BaseView.h"
#include<memory>
class ViewManger
{
public:
    void start();
    void setNext(std::unique_ptr<BaseView>next);
    static ViewManger& getInstance()
    {
        static ViewManger instance;
        return instance;
    }
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
    ViewManger() {};
    ~ViewManger() {};
    ViewManger(const ViewManger&);
    ViewManger& operator=(const ViewManger&);
};

