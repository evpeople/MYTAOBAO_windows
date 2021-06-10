#pragma once
#include<vector>
#include<memory>
#include<algorithm>
#include"Goods.h"
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
class shoppingCart
{
public:
    vupOfBaseGoods& getCart();
    double calShoppingCart();
    void addShoppingCart(Json::Value& goods,long long int last,std::string);//todo:增加和减少freeze过多，若存在，则增加数量，不存在，则增加商品。
    void minShoppingCart(Json::Value& goods, long long int last,std::string);// 若存在，则减少数量，若减少为0，则删去，不存在，则显示错我
    void buyAll();
    void show();
    int search(std::string name);
private:
    vupOfBaseGoods shoppingCart;
};

