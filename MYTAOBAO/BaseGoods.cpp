#include "BaseGoods.h"

double BaseGoods::getOriginalPrice()
{
    return price;
}

long long int BaseGoods::getRemain()
{
    return numberRemain;
}

std::string BaseGoods::getName()
{
    return name;
}

void BaseGoods::getDescription()
{
    std::cout << "��ֻ��һ����Ϊ" << name << "����ͨ��"<<BaseGoods::Description<<"��" << std::endl;
}

void BaseGoods::setDescription(std::string newDescription)
{
    BaseGoods::Description = newDescription;
}
