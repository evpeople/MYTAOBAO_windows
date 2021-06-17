#include "Cloths.h"
using std::string;
double Cloths::discount = 1;
string Cloths::type = "Cloths";
Cloths::Cloths(long long int newNumberRemain, double newPrice, std::string newName, std::string des, std::string owner)
    :BaseGoods(newNumberRemain, newPrice, newName, des, owner)
{
}
double Cloths::getPrice()
{
    return getOriginalPrice() * Cloths::discount;
}

std::string Cloths::getType()
{
    return Cloths::type;
}

void Cloths::setDiscount(double newDiscount)
{
    Cloths::discount = newDiscount;
}

double Cloths::getDiscount()
{
    return discount;
}