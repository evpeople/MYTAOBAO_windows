#pragma once
#include<string>
#include<iostream>
class BaseGoods
{
public:
    BaseGoods( long long int newNumberRemain, double newPrice, std::string newName,std::string des)
        : numberRemain(newNumberRemain), price(newPrice), name(newName),description(des) {}
    BaseGoods(const BaseGoods& temp)
        : numberRemain(temp.numberRemain),price(temp.price),name(temp.name),description(temp.description){}
    BaseGoods& operator=(BaseGoods&& temp);
    virtual double getOriginalPrice()final;
    virtual long long int getRemain()final;
    virtual std::string getName()final;
    virtual double getPrice() = 0;
    virtual std::string getType() = 0;
    virtual std::string getDescription()final;
    virtual void setDiscount(double newDiscount) = 0;

private:
    long long int numberRemain;
    double price;
    std::string name;
    std::string description;
};

