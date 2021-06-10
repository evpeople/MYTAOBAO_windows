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
    void addShoppingCart(Json::Value& goods,long long int last,std::string);//todo:���Ӻͼ���freeze���࣬�����ڣ������������������ڣ���������Ʒ��
    void minShoppingCart(Json::Value& goods, long long int last,std::string);// �����ڣ������������������Ϊ0����ɾȥ�������ڣ�����ʾ����
    void buyAll();
    void show();
    int search(std::string name);
private:
    vupOfBaseGoods shoppingCart;
};

