#include "BaseGoods.h"
using namespace std;
BaseGoods& BaseGoods::operator=(BaseGoods&& temp)
{
    if (this!=&temp)
    {
        this->description = temp.description;
        this->name = temp.name;
        this->price = temp.price;
        this->numberRemain = temp.numberRemain;
    }
    return *this;
}
double BaseGoods::getOriginalPrice()
{
    return price;
}

long long int BaseGoods::getRemain()
{
    return numberRemain;
}

string BaseGoods::getName()
{
    return name;
}

std::string BaseGoods::getDescription()
{
    return description;
}

