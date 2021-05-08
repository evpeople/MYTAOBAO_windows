#include "EleProduct.h"
double EleProduct::discount = 1;
std::string EleProduct::type = "EleProduct";
EleProduct::EleProduct( long long int newNumberRemain, double newPrice, std::string newName)
    :BaseGoods(newNumberRemain, newPrice, newName)
{
    setDescription("���Ӳ�Ʒ");
}
double EleProduct::getPrice()
{
    return getOriginalPrice() * EleProduct::discount;
}

std::string EleProduct::getType()
{
    return EleProduct::type;
}



void EleProduct::setDiscount(double newDiscount)
{
    EleProduct::discount = newDiscount;
}
