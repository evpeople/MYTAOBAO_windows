#pragma once
#include "BaseView.h"
class BuyView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
};

