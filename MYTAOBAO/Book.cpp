#include "Book.h"
using std::string;
double Book::discount = 1;
const string Book::type = "Book";
Book::Book( long long int newNumberRemain, double newPrice, string newName)
    :BaseGoods(newNumberRemain,newPrice,newName)
{
    setDescription(" È");
}
double Book::getPrice()
{
    return getOriginalPrice()*Book::discount;
}

std::string Book::getType()
{
    return Book::type;
}



void Book::setDiscount(double newDiscount)
{
    Book::discount = newDiscount;
}
