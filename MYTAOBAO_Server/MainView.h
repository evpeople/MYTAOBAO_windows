#pragma once
#include "BaseView.h"
class MainView :
    public BaseView
{
public:
    virtual void show()override;
    virtual void viewInput()override;
};
