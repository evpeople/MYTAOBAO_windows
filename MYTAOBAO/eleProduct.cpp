#include "EleProduct.h"
double EleProduct::discount = 1;
EleProduct::EleProduct(long long int newId, long long int newNumberRemain, double newPrice, std::string newName)
    :BaseGoods(newId, newNumberRemain, newPrice, newName)
{
    setDescription(" È");
}
double EleProduct::getPrice()
{
    return getOriginalPrice() * EleProduct::discount;
}



void EleProduct::setDiscount(double newDiscount)
{
    EleProduct::discount = newDiscount;
}
