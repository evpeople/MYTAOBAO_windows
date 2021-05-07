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

void BaseGoods::getDescription()
{
    cout << "这只是一本名为" << name << "的普通的"<<BaseGoods::Description<<"！" << endl;
}

void BaseGoods::setDescription(string newDescription)
{
    BaseGoods::Description = newDescription;
}
