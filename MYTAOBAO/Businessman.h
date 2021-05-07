#pragma once
#include "BaseUsr.h"
#include<vector>
#include"Goods.h"
class Businessman :
    public BaseUsr
{
public:
    Businessman(std::string name, std::string PassWd);
    Businessman();
    virtual void storage()override;
    virtual bool login()override;
    virtual USRTYPE getType()override;
    void static setAddress(std::string newAddress);
    std::string static getAddress();
    virtual void discount()override;
    virtual void setGoods()override;
private:
    long long int id;
    std::vector<BaseGoods*>busSGooods;
    static USRTYPE type;
    static long long int totalId;
    static std::string  storageAddress;
};

