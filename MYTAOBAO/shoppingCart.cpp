#include "shoppingCart.h"
#include"json/json.h"
#include"Businessman.h"
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

void shoppingCart::addShoppingCart(Json::Value& good, long long int last,string usrName)
{
    if (good["remain"].asInt64()<last)
    {
        cout << "购买了太多，没有这么多卖" << endl;
        return;
    }
    else
    {
        good["isFreeze"] = last;
    }
    int index = search(good["name"].asString());
    if (index==-1)
    {
        string name = good["name"].asString();
        double price=good["price"].asDouble();
        string des=good["description"].asString();
        string owner = good["owner"].asString();
        if (good["type"].asString() == "Book")
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new Book{last,price,name,des,owner}));
        }
        else if (good["type"].asString() == "Cloths")
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new Cloths{last,price,name,des,owner}));
        }
        else
        {
            shoppingCart.push_back(unique_ptr<BaseGoods>(new EleProduct{last,price,name,des,owner}));
        }
    }
    else
    {
        shoppingCart[index]->setRemain(shoppingCart[index]->getRemain() + last);
    }
}

void shoppingCart::minShoppingCart(Json::Value& good, long long int last, std::string usrName)
{
    int index = search(good["name"].asString());
    if (index == -1)
    {
        cout << "没得可删！" << endl;
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

void shoppingCart::buyAll()
{
    Businessman* tempOwner = new Businessman();
    for_each(shoppingCart.begin(), shoppingCart.end(), [&tempOwner](unique_ptr<BaseGoods>& up) {

        cout << "name is " << up->getName() << endl;
        cout << "the number you buy is " << up->getRemain() << endl;
        string owner = up->getOwner();
        tempOwner->loginWithoutChecked(owner);
        tempOwner->dealBuy(up->getName(), up->getRemain());
        //tempOwner->setMoney(tempOwner->getMoney() + up->getPrice() * up->getRemain());
        //tempOwner->//todo: free goods
        tempOwner->storage();
        });
    delete tempOwner;
    shoppingCart.clear();
}

void shoppingCart::show()
{
    for_each(shoppingCart.begin(), shoppingCart.end(), [](unique_ptr<BaseGoods>& up) {

        cout<<"name is "<<up->getName()<<endl;
        cout<<"price is "<<up->getPrice()<<endl;
        cout<<"the number you buy is " <<up->getRemain()<<endl;
        cout<<"Type is "<<up->getType()<<endl;
        cout<<"description is "<<up->getDescription()<<endl;
        });
}

void shoppingCart::makeBill()
{
    Businessman* tempOwner = new Businessman();
    for_each(shoppingCart.begin(), shoppingCart.end(), [&tempOwner](unique_ptr<BaseGoods>& up) {

        cout << "Goods name is " << up->getName() << endl;
        cout << "the number Freeze is " << up->getRemain() << endl;
        string owner = up->getOwner();
        tempOwner->loginWithoutChecked(owner);
        tempOwner->setGoodsFreeze(up->getName(), up->getRemain());
        //todo: 已经设置了的freeze被覆盖存储的问题
        //tempOwner->setMoney(tempOwner->getMoney() + up->getPrice() * up->getRemain());
        //tempOwner->//todo: free goods
        //tempOwner->storage();
        });
    delete tempOwner;
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

