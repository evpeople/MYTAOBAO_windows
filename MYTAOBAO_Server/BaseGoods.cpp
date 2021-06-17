#include "BaseGoods.h"
using namespace std;
void BaseGoods::storage()
{
}
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

void BaseGoods::setDescription(std::string newDes)
{
    description = newDes;
}


void BaseGoods::setName(std::string newname)
{
    name = newname;
}

void BaseGoods::setFreeze(long long int freeze)
{
    isFreeze = freeze;
}


void BaseGoods::setRemain(long long int newReamin)
{
    numberRemain = newReamin;
}

void BaseGoods::setOriginalPrice(double newPrice)
{
    price = newPrice;
}

std::string BaseGoods::getOwner()
{
    return owner;
}

std::string BaseGoods::getDescription()
{
    return description;
}

long long int BaseGoods::getFreeze()
{
    return isFreeze;
}

