#include "Customer.h"
#include"Goods.h"
#include <iostream>
#include <io.h>
#include <memory>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios_base;
using std::unique_ptr;
long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
string Customer::storageAddress = ".";
Customer::Customer(string name, string PassWd)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    cout << "您想充值多少钱" << endl;
    cin >> money;
}
Customer::Customer(string name, string PassWd,double money)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    this->money= money;
}
Customer::Customer() :BaseUsr{ "0","0" }
{
    id = 0;
    money = 0;
}

void Customer::storage()
{
    Json::Value temp,shoppingFartJson;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = id;
    temp["usrName"] = getUsrName();
    temp["usrPass"] = getUsrPassWord();
    temp["usrType"] = "Customer";
    temp["money"] = money;

    Json::StreamWriterBuilder fwCbuilder;
    static Json::Value def = []() {
        Json::Value def;
        Json::StreamWriterBuilder::setDefaults(&def);
        def["emitUTF8"] = true;
        return def;
    }();
    fwbuilder.settings_ = def;
    int serial = 0;
    shoppingCart = shopCart.getCart();
    for_each(shoppingCart.begin(), shoppingCart.end(), [&shoppingFartJson, &serial](unique_ptr<BaseGoods>& up) {

        shoppingFartJson[serial]["name"] = up->getName();
        shoppingFartJson[serial]["price"] = up->getPrice();
        shoppingFartJson[serial]["remain"] = up->getRemain();//remain 为买了多少
        shoppingFartJson[serial]["type"] = up->getType();
        shoppingFartJson[serial]["description"] = up->getDescription();
        //shoppingFartJson[serial]["owner"] = up->getOwner();
        //shoppingFartJson[serial]["isFreeze"] = up->getFreeze();
        serial++;
        });
    temp["shopping"] = shoppingFartJson;
    string outFile = Customer::storageAddress + getUsrName() + ".usr";
    ofstream fout{ outFile ,ios_base::out};
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp, &fout);
    fout.close();
}

bool Customer::login(string tempUsr,string passWord)
{

    string inPath = Customer::storageAddress + tempUsr + ".usr";

    ifstream fin;
    fin.open(inPath);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }

        id = root["usrID"].asInt64();
        setUsrName(root["usrName"].asString());
        setUsrPassWord(root["usrPass"].asString());
        money = root["money"].asDouble();
        //todo:购物车入内存


        fin.close();
        //passWord = "evp";
        if (auth(passWord))
        {
            cout << "登陆成功" << endl;
            return true;
        }
        else
        {
            cout << "密码错误" << endl;
            return false;
        }
    }
    else
    {
        cout << "抱歉，此用户不存在！，请注册" << endl;
    }
    return false;
}

USRTYPE Customer::getType()
{
    return Customer::type;
}

void Customer::balance()
{
    cout << "你现在还剩" << money << "元钱，充值请输入8" << endl;
    int choice;
    cin >> choice;
    if (choice == 8)
    {
        cout << "请输入充值多少钱" << endl;
        cin >> choice;
        money += choice;
    }
    else
    {
        cin.clear();
        cin.ignore();
        return;
    }
}

bool Customer::buySomeThing(double price)
{
    if (price > money)
    {
        cout << "抱歉，你的钱不够多" << endl;
        return false;
    }
    else
    {
        money -= price;
        cout << "已购买，你还剩" << money << "这么多钱" << endl;
        return true;
    }
}

int Customer::getId()
{
    return id;
}

bool Customer::addInShoppingCart(Json::Value& good,long long int last)
{
    shopCart.addShoppingCart(good, last,getUsrName());
    //last 是买多少


    //string name=good->getName();
    //double price=good->getPrice();
    //string des=good->getDescription();
    //if (good->getType()=="Book")
    //{
    //    shoppingCart.push_back(unique_ptr<BaseGoods>(new Book{last,price,name,des,getUsrName()}));
    //}
    //else if (good->getType()=="Cloths")
    //{
    //    shoppingCart.push_back(unique_ptr<BaseGoods>(new Cloths{last,price,name,des,getUsrName()}));
    //}
    //else
    //{

    //    shoppingCart.push_back(unique_ptr<BaseGoods>(new EleProduct{last,price,name,des,getUsrName()}));
    //}
    
//todo:被冻结的问题。
    //good->setFreeze(last+good->getFreeze());

    return false;
}

void Customer::minShoppingCart(Json::Value& goods, long long int last)
{
    shopCart.minShoppingCart(goods, last,getUsrName());
    //goods->setFreeze(goods->getFreeze()-last);
}

void Customer::showCart()
{
    shopCart.show();
}

bool Customer::buyAllThing()
{
    bool flag = false;
    if (getMoney()>=shopCart.calShoppingCart())
    {
        shopCart.buyAll();
        setMoney(getMoney() - shopCart.calShoppingCart());
        flag = true;
    }
    else
    {
        cout << "钱不够" << endl;
    }
    return flag;
}

double Customer::calShoppingCart()
{
    return shopCart.calShoppingCart();
}


double Customer::getMoney()
{
    return money;
}

void Customer::setMoney(double newMoney)
{
    money = newMoney;
}

void Customer::setAddress(string newAddress)
{
    Customer::storageAddress = newAddress;
}

string Customer::getAddress()
{
    return Customer::storageAddress;
}

//_finddata_t fileInfo;
//long handle = _findfirst(inPath.c_str(), &fileInfo);
//if (handle==-1)//todo: 异常处理
//{
//    std::cout << "此时还没有文件" << std::endl;
//    return false;
//}
//int finded = 0;
//do
//{
//    if ((tempUsr+".usr")==fileInfo.name)
//    {
//        finded = 1;
//        break;
//    }
//} while (!_findnext(handle,&fileInfo);
//_findclose(handle);

Customer::~Customer()
{
    int a = 1;
}
