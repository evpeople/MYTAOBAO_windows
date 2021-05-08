#pragma once
#include "BaseGoods.h"
class EleProduct :
    public BaseGoods
{
public:
    EleProduct( long long int newNumberRemain, double newPrice, std::string newName,std::string des);
    virtual double getPrice()override;
    virtual std::string getType()override;
    virtual void setDiscount(double newDiscount)override;
private:
    static std::string type;   
    static double discount;
};

