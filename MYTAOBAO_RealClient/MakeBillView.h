#pragma once
#include "BaseView.h"
class MakeBillView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
private:
    void buy();
};

