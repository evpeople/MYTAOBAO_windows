#include "BaseGoods.h"
using namespace std;
double BaseGoods::getOriginalPrice()
{
    return price;
}

long long int BaseGoods::getRemain()
{
    return numberRemain;
}

string BaseGoods::getName()
{
    return name;
}

std::string BaseGoods::getDescription()
{
    return description;
}

void BaseGoods::setDescription(string newDescription)
{
    string tempDes;
    cout << "���ṩ��Ʒ����ϸ������" << endl;
    cin >> tempDes;
    description = tempDes;
}
