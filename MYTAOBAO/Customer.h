#pragma once
#include "BaseUsr.h"
class Customer :public BaseUsr
{
public:

    Customer(std::string name, std::string PassWd);
    virtual void storage()override;
    ~Customer();
private:
    long long int id;
    static long long int totalId;
    static USRTYPE type;
    static std::string  storageAddress;
};

