#include "EleProduct.h"
double EleProduct::discount = 1;
EleProduct::EleProduct( long long int newNumberRemain, double newPrice, std::string newName)
    :BaseGoods(newNumberRemain, newPrice, newName)
{
    setDescription("电子产品");
}
double EleProduct::getPrice()
{
    return getOriginalPrice() * EleProduct::discount;
}



void EleProduct::setDiscount(double newDiscount)
{
    EleProduct::discount = newDiscount;
}
