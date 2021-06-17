#pragma once
#include "BaseView.h"
class LoginView :
    public BaseView
{
public:
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
};
