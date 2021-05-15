#pragma once
#include "BaseView.h"
class DisCountView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(int choice, double discount);
};

