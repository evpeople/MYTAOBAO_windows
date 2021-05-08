#pragma once
#include "BaseGoods.h"
#include<iostream>
class Book :
    public BaseGoods
{
public:
    Book(long long int newNumberRemain, double newPrice, std::string newName, std::string des);
    virtual double getPrice()override;
    virtual std::string getType();
    virtual void setDiscount(double newDiscount)override;
private:
    static double discount;
    const static std::string type;
};

