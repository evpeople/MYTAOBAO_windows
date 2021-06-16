#pragma once
#include "BaseGoods.h"
class Cloths :
    public BaseGoods
{
public:
    Cloths(long long int newNumberRemain, double newPrice, std::string newName, std::string des, std::string owner);
    virtual double getPrice()override;
    virtual std::string getType()override;
    static void setDiscount(double newDiscount);
    static double getDiscount();
private:
    static double discount;
    static std::string type;
};

