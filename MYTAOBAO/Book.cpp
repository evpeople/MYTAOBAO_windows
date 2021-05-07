#include "Book.h"
using std::string;
double Book::discount = 1;
Book::Book( long long int newNumberRemain, double newPrice, string newName)
    :BaseGoods(newNumberRemain,newPrice,newName)
{
    setDescription(" È");
}
double Book::getPrice()
{
    return getOriginalPrice()*Book::discount;
}



void Book::setDiscount(double newDiscount)
{
    Book::discount = newDiscount;
}
