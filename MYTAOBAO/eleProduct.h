#pragma once
#include "BaseGoods.h"
class eleProduct :
    public BaseGoods
{
public:
    eleProduct(long long int newId, long long int newNumberRemain, double newPrice, std::string newName);
    virtual double getPrice()override;
    virtual void setDiscount(double newDiscount)override;
private:
    static double discount;
};
};

