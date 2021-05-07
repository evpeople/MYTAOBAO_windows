#include "Cloths.h"
using std::string;
double Cloths::discount = 1;
Cloths::Cloths(long long int newNumberRemain, double newPrice, string newName)
    :BaseGoods(newNumberRemain, newPrice, newName)
{
    setDescription("ÒÂ·þ");
}
double Cloths::getPrice()
{
    return getOriginalPrice() * Cloths::discount;
}



void Cloths::setDiscount(double newDiscount)
{
    Cloths::discount = newDiscount;
}