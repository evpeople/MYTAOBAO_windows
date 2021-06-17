#pragma once
#include "BaseView.h"
class BusinessmanView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    void addGoods(std::vector<std::unique_ptr<BaseGoods>>& temp);
    bool dealInput(std::string name, std::string pass, int choice);
};
