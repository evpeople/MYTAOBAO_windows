#include "shoppingCart.h"
#include"json/json.h"
#include"Businessman.h"
#include"Server.h"
#include<WinSock2.h>
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

void shoppingCart::addShoppingCart(Json::Value& good, long long int last,string usrName,int id)
{
    if (good["remain"].asInt64()<last)
    {
        cout << "购买了太多，没有这么多卖" << endl;
        send(Server::sockS[id], "买的太多了", 11, 0);
        return;
    }
    else
    {
        //good["isFreeze"] = last;
       //todo: 此时不用冻住
       
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
        cout << "添加了新种类" << endl;
        send(Server::sockS[id], "添加了新的种类", 15, 0);
    }
    else
    {
        shoppingCart[index]->setRemain(shoppingCart[index]->getRemain() + last);
        send(Server::sockS[id], "增加了数量", 11, 0);
    }

}

void shoppingCart::minShoppingCart(Json::Value& good, long long int last, std::string usrName,int id)
{
    int index = search(good["name"].asString());
    if (index == -1)
    {
        send(Server::sockS[id], "没得可删", 9, 0);
        cout << "没得可删！" << endl;
    }
    else
    {
        send(Server::sockS[id], "已经减少了", 11, 0);
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

void shoppingCart::show(int id)
{
    for_each(shoppingCart.begin(), shoppingCart.end(), [&id](unique_ptr<BaseGoods>& up) {
        string out = "name is" + up->getName() + "\nprice is" + to_string(up->getPrice()) + "\nthe number you buy is" + to_string(up->getRemain()) + "\nIts type is" + up->getType() + "\ndescription is" + up->getDescription();
        cout << out;
        send(Server::sockS[id], out.c_str(), out.size(), 0);
        char a[20];
        recv(Server::sockS[id], a, 20, 0);
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
        //tempOwner->setMoney(tempOwner->getMoney() + up->getPrice() * up->getRemain());
        //tempOwner->//todo: free goods
        //tempOwner->storage();
        });
    delete tempOwner;
}

void shoppingCart::clearBill()
{
    Businessman* tempOwner = new Businessman();
    for_each(shoppingCart.begin(), shoppingCart.end(), [&tempOwner](unique_ptr<BaseGoods>& up) {

        cout << "Goods name is " << up->getName() << endl;
        cout << "the number Freeze is " << up->getRemain() << endl;
        string owner = up->getOwner();
        tempOwner->loginWithoutChecked(owner);
        if ((up->getFreeze()- up->getRemain())>0)
        {
            tempOwner->setGoodsFreeze(up->getName(),up->getFreeze() - up->getRemain());
        }
        else
        {
            tempOwner->setGoodsFreeze(up->getName(),0);
        }
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

