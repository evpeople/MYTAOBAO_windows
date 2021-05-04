#pragma once
#include "BaseUsr.h"
class Customer :public BaseUsr
{
public:
    Customer();
    Customer(string name, string PassWd) :BaseUsr{name, PassWd
}{}
     ~Customer();
};

