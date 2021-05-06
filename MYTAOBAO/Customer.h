#pragma once
#include "BaseUsr.h"
class Customer :public BaseUsr
{
public:

    Customer(std::string name, std::string PassWd);
    Customer();
    virtual void storage()override;
    virtual bool login()override;
    virtual USRTYPE getType()override;
    virtual void balance()override;
    virtual void buySomeThing(double)override;
    virtual int getId();
    void static setAddress(std::string newAddress);
    std::string static getAddress();
    ~Customer();
private:
    long long int id;
    double money;
    static USRTYPE type;
    static long long int totalId;
    static std::string  storageAddress;
};

