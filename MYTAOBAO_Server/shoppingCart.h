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
    void addShoppingCart(Json::Value& goods, long long int last, std::string, int id);//todo:���Ӻͼ���freeze���࣬�����ڣ������������������ڣ���������Ʒ��
    void minShoppingCart(Json::Value& goods, long long int last, std::string, int id);// �����ڣ������������������Ϊ0����ɾȥ�������ڣ�����ʾ����
    void buyAll();
    void show(int id);
    void makeBill();
    void clearBill();
    int search(std::string name);
private:
    vupOfBaseGoods shoppingCart;
};
