#pragma once
#include "BaseGoods.h"
class Cloths :
    public BaseGoods
{
public:
    Cloths ( long long int newNumberRemain, double newPrice, std::string newName);
    virtual double getPrice()override;
    virtual std::string getType()override;
    virtual void setDiscount(double newDiscount)override;
private:
    static double discount;
    static std::string type;
};

