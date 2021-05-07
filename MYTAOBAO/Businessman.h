#pragma once
#include "BaseUsr.h"
#include<vector>
#include<unordered_map>
#include<memory>
#include<algorithm>
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
    int goods;;
    std::vector<std::unique_ptr<BaseGoods>>busSGooods;
    static USRTYPE type;
    static long long int totalId;
    static std::string  storageAddress;
};

