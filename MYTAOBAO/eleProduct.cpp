#include "eleProduct.h"
double eleProduct::discount = 1;
eleProduct::eleProduct(long long int newId, long long int newNumberRemain, double newPrice, std::string newName)
    :BaseGoods(newId, newNumberRemain, newPrice, newName)
{
    setDescription(" È");
}
double eleProduct::getPrice()
{
    return getOriginalPrice() * eleProduct::discount;
}



void eleProduct::setDiscount(double newDiscount)
{
    Book::discount = newDiscount;
}
