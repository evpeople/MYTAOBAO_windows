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
    cout << "请提供商品的详细的描述" << endl;
    cin >> tempDes;
    description = tempDes;
}
