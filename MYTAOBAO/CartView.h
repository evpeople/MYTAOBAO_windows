#pragma once
#include"BaseView.h"
class CartView:
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
private:
    void search();
    bool dealBuy();//todo: 整合消费车支付订单，扣除转移钱财。remain为买了多少
    //show
    void search(std::string, Json::Value& ansGood);
    void search(std::string, std::vector<Json::Value>& ansGoods);
};
};

