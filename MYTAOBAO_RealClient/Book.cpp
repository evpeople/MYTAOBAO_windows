#include "Book.h"
using std::string;
double Book::discount = 1;
const string Book::type = "Book";
Book::Book(long long int newNumberRemain, double newPrice, std::string newName, std::string des, std::string owner)
    : BaseGoods(newNumberRemain, newPrice, newName, des, owner)
{
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

double Book::getDiscount()
{
    return discount;
}
