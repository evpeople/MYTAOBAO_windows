#include "shoppingCart.h"

using namespace std;

vupOfBaseGoods& shoppingCart::getCart()
{
    return shoppingCart;
}

double shoppingCart::calShoppingCart()
{
    double totalPrice;
    for_each(shoppingCart.begin(), shoppingCart.end(), [&totalPrice](unique_ptr<BaseGoods>& up) {
        
        totalPrice = up->getPrice() * up->getRemain();
        //shoppingFartJson[serial]["owner"] = up->getOwner();
        //shoppingFartJson[serial]["isFreeze"] = up->getFreeze();
        });
    return totalPrice;
}

void shoppingCart::addShoppingCart(std::unique_ptr<BaseGoods>& good, long long int last,string usrName)
{
    int index = search(good->getName());
    if (index==-1)
    {
        string name=good->getName();
        double price=good->getPrice();
        string des=good->getDescription();
        if (good->getType()=="Book")
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new Book{last,price,name,des,usrName}));
        }
        else if (good->getType()=="Cloths")
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new Cloths{last,price,name,des,usrName}));
        }
        else
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new EleProduct{last,price,name,des,usrName}));
        }
    }
    else
    {
        shoppingCart[index]->setRemain(shoppingCart[index]->getRemain() + last);
    }
}

void shoppingCart::minShoppingCart(std::unique_ptr<BaseGoods>& good, long long int last, std::string usrName)
{
    int index = search(good->getName());
    if (index == -1)
    {
        cout << "Ã»µÃ¿ÉÉ¾£¡" << endl;
    }
    else
    {
        shoppingCart[index]->setRemain(shoppingCart[index]->getRemain() - last);
        if (shoppingCart[index]->getRemain()==0)
        {
            shoppingCart.erase(shoppingCart.begin()+index);
        }
    }
}

int shoppingCart::search(std::string name)
{
    for (size_t i = 0; i < shoppingCart.size(); i++)
    {
        if (shoppingCart[i]->getName() == name)
            return i;
    }
    return -1;
}

