#include "shoppingCart.h"
#include"json/json.h"
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

void shoppingCart::buyAll()
{
    for_each(shoppingCart.begin(), shoppingCart.end(), [](unique_ptr<BaseGoods>& up) {

        cout << "name is " << up->getName() << endl;
        cout << "price is " << up->getPrice() << endl;
        cout << "the number you buy is " << up->getRemain() << endl;
        cout << "Type is " << up->getType() << endl;
        cout << "description is " << up->getDescription() << endl;
        });

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

int shoppingCart::search(std::string name)
{
    for (size_t i = 0; i < shoppingCart.size(); i++)
    {
        if (shoppingCart[i]->getName() == name)
            return i;
    }
    return -1;
}

