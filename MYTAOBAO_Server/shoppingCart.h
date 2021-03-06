#pragma once
#include<vector>
#include<memory>
#include<algorithm>
#include<json/json.h>
#include"Goods.h"
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
class shoppingCart
{
public:
    vupOfBaseGoods& getCart();
    double calShoppingCart();
    void addShoppingCart(Json::Value& goods, long long int last, std::string, int id,bool flag);//todo:增加和减少freeze过多，若存在，则增加数量，不存在，则增加商品。
    void minShoppingCart(Json::Value& goods, long long int last, std::string, int id);// 若存在，则减少数量，若减少为0，则删去，不存在，则显示错我
    void buyAll();
    void show(int id);
    void makeBill();
    void clearBill();
    int search(std::string name);
private:
    vupOfBaseGoods shoppingCart;
};
