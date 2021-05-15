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
    static void setDiscount(double newDiscount);
    static double getDiscount();
private:
    static double discount;
    const static std::string type;
};

