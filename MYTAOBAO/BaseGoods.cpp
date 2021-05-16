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

std::string BaseGoods::getOwner()
{
    return owner;
}

std::string BaseGoods::getDescription()
{
    return description;
}

