#pragma once
#include "BaseView.h"
class FailureView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
};

