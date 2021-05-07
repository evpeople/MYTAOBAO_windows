#pragma once
#include "BaseGoods.h"
#include<iostream>
class Book :
    public BaseGoods
{
public:
    Book( long long int newNumberRemain, double newPrice, std::string newName);
    virtual double getPrice()override;
    virtual void setDiscount(double newDiscount)override;
private:
    static double discount;
};

