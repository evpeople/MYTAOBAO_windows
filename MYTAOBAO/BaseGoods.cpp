#include "BaseGoods.h"

double BaseGoods::getOriginalPrice()
{
    return price;
}

long long int BaseGoods::getRemain()
{
    return numberRemain;
}

std::string BaseGoods::getName()
{
    return name;
}

void BaseGoods::getDescription()
{
    std::cout << "这只是一本名为" << name << "的普通的"<<BaseGoods::Description<<"！" << std::endl;
}

void BaseGoods::setDescription(std::string newDescription)
{
    BaseGoods::Description = newDescription;
}
