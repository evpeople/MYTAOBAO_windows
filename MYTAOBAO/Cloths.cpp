#include "Cloths.h"
using std::string;
double Cloths::discount = 1;
Cloths::Cloths(long long int newId, long long int newNumberRemain, double newPrice, string newName)
    :BaseGoods(newId, newNumberRemain, newPrice, newName)
{
    setDescription(" È");
}
double Cloths::getPrice()
{
    return getOriginalPrice() * Cloths::discount;
}



void Cloths::setDiscount(double newDiscount)
{
    Cloths::discount = newDiscount;
}