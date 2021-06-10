#pragma once
#include<string>
#include<iostream>
class BaseGoods
{
public:
    BaseGoods( long long int newNumberRemain, double newPrice, std::string newName,std::string des,std::string owner)
        : numberRemain(newNumberRemain), price(newPrice), name(newName), description(des), owner(owner) {
        isFreeze = 0;
    }
    virtual void storage()final;
    virtual double getOriginalPrice()final;
    virtual long long int getRemain()final;
    virtual std::string getName()final;
    virtual std::string getOwner()final;
    virtual double getPrice() = 0;
    virtual std::string getType() = 0;
    virtual std::string getDescription()final;
    virtual long long int getFreeze()final;
            
    virtual void setDescription(std::string newDes)final;
    virtual void  setName(std::string newName)final;
    virtual void setFreeze(long long int freeze)final;
    virtual void setRemain(long long int newReamin)final;
    virtual void setOriginalPrice(double newPrice)final;

private:
    long long int numberRemain;
    double price;
    long long int isFreeze;
    std::string name;
    std::string description;
    std::string owner;
};

