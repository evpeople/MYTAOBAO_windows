#pragma once
#include<string>
#include<iostream>
class BaseGoods
{
public:
    BaseGoods( long long int newNumberRemain, double newPrice, std::string newName,std::string des,std::string owner)
        : numberRemain(newNumberRemain), price(newPrice), name(newName),description(des),owner(owner) {}
    virtual double getOriginalPrice()final;
    virtual long long int getRemain()final;
    virtual std::string getName()final;
    virtual double getPrice() = 0;
    virtual std::string getType() = 0;
    virtual std::string getDescription()final;


private:
    long long int numberRemain;
    double price;
    std::string name;
    std::string description;
    std::string owner;
};

