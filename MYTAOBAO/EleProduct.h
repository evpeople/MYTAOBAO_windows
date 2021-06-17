#pragma once
#include "BaseGoods.h"
class EleProduct :
    public BaseGoods
{
public:
    EleProduct(long long int newNumberRemain, double newPrice, std::string newName, std::string des, std::string owner);
    virtual double getPrice()override;
    virtual std::string getType()override;
    static void setDiscount(double newDiscount);
    static double getDiscount();
private:
private:
    static std::string type;
    static double discount;
};
