#pragma once
#include "BaseUsr.h"
#include<vector>
#include<unordered_map>
#include<memory>
#include<algorithm>
#include"Goods.h"
typedef std::vector<std::unique_ptr<BaseGoods>> vupOfBaseGoods;
class Businessman :
    public BaseUsr
{
public:
    Businessman(std::string name, std::string PassWd);
    Businessman();
    Businessman(std::string name,std::string PassWd, vupOfBaseGoods& busSGooods, int goodsType);
    virtual void storage()override;
    virtual bool loginWithoutChecked(std::string tempUsr);
    virtual bool login(std::string tempUsr, std::string passWord)override;
    virtual USRTYPE getType()override;
    void static setAddress(std::string newAddress);
    void dealBuy(std::string goodsName,long long int goodsNum);
    std::string static getAddress();
    virtual void discount(int kind  ,double)override;
    virtual vupOfBaseGoods& getGoods()override;
    //virtual void  setGoods()override;
private:
    long long int id;
    int goodsType;;
    vupOfBaseGoods busSGooods;
    //todo: 没有给商人钱的属性
    //std::unordered_map<std::string, vupOfBaseGoods>busSGooods;
    static USRTYPE type;
    static long long int totalId;
    inline  static bool isLogin=false;
    static std::string  storageAddress;
};

