#pragma once
#include"BaseView.h"
class CartView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
private:
    void showCart();
    void buyAll();
    void addGoods();
    void minGoods();
    bool dealBuy();
    void search(std::string, Json::Value& ansGood);
};
