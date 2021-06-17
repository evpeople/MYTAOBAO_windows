#pragma once
#include<memory>
#include"BaseView.h"

class ViewManger
{
public:
    void start();
    void setNext(std::unique_ptr<BaseView>next);
    void setNow(std::unique_ptr<BaseView>now);
    void sleepMs(int ms);
    static  ViewManger& getInstance(int ViewId);
    void setId(int id);
    int getId();
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
    ViewManger() ;
    ~ViewManger() {};
    ViewManger& operator=(const ViewManger& s);
    ViewManger(const ViewManger& obj);
protected:

private:
    int id;
    std::unique_ptr<BaseView> viewNext;
    std::unique_ptr<BaseView> viewCurrent;
    static std::vector<ViewManger>viewS;
};

