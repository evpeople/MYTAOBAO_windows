#include "Cloths.h"
using std::string;
double Cloths::discount = 1;
string Cloths::type = "Cloths";
Cloths::Cloths(long long int newNumberRemain, double newPrice, string newName,string des)
    :BaseGoods(newNumberRemain, newPrice, newName,des)
{
    setDescription("ÒÂ·þ");
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