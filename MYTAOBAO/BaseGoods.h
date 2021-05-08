#pragma once
#include<string>
#include<iostream>
class BaseGoods
{
public:
    BaseGoods( long long int newNumberRemain, double newPrice, std::string newName)
        : numberRemain(newNumberRemain), price(newPrice), name(newName) {}
    virtual double getOriginalPrice()final;
    virtual long long int getRemain()final;
    virtual std::string getName()final;
    virtual double getPrice() = 0;
    virtual std::string getType() = 0;
    virtual std::string getDescription();
    virtual void setDiscount(double newDiscount) = 0;
protected:
    virtual void setDescription(std::string newDescription);
private:
    long long int numberRemain;
    double price;
    std::string name;
    static std::string Description;
};

