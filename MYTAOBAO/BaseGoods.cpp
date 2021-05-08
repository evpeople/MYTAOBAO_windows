#include "BaseGoods.h"
using namespace std;
string BaseGoods::Description = ".";
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
    return "这只是一本名为" + name + "的普通的" + BaseGoods::Description;
}

void BaseGoods::setDescription(string newDescription)
{
    BaseGoods::Description = newDescription;
}
