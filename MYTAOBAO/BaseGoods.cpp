#include "BaseGoods.h"
using namespace std;

double BaseGoods::getOriginalPrice()
{
    return price;
}

long long int BaseGoods::getRemain()
{
    return numberRemain;
}

string BaseGoods::getName()
{
    return name;
}

void BaseGoods::getDescription()
{
    cout << "��ֻ��һ����Ϊ" << name << "����ͨ��"<<BaseGoods::Description<<"��" << endl;
}

void BaseGoods::setDescription(string newDescription)
{
    BaseGoods::Description = newDescription;
}
