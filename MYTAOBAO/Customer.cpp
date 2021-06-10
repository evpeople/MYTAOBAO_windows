#include "Customer.h"
#include"Goods.h"
#include <iostream>
#include <io.h>
#include <memory>


using namespace std;

long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
string Customer::storageAddress = ".";

Customer::Customer(string name, string PassWd)
    :BaseUsr{ name, PassWd }
{
    id = totalId;
    totalId++;
    //shoppingCart = shopCart.getCart();
    cout << "您想充值多少钱" << endl;
    double money;
    cin >> money;
    setMoney(money);
}
Customer::Customer(string name, string PassWd,double money)
    :BaseUsr{ name, PassWd }
{
    //shoppingCart = shopCart.getCart();
    id = totalId;
    totalId++;
    setMoney(money);
}
Customer::Customer() :BaseUsr{ "0","0" }
{
    id = 0;
    setMoney(0);
    //shoppingCart = shopCart.getCart();
}



USRTYPE Customer::getType()
{
    return Customer::type;
}



Customer::~Customer()
{
}

void Customer::inputDouble(double& num)
{
        cin >> num;
        while (!cin.good())
        {
            cout << "只能是数字" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin.sync();

            cin >> num;
        }
}

void Customer::storage()
{
    Json::Value temp,shoppingFartJson;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = id;
    temp["usrName"] = getUsrName();
    temp["usrPass"] = getUsrPassWord();
    temp["usrType"] = "Customer";
    temp["money"] = getMoney();

    Json::StreamWriterBuilder fwCbuilder;
    static Json::Value def = []() {
        Json::Value def;
        Json::StreamWriterBuilder::setDefaults(&def);
        def["emitUTF8"] = true;
        return def;
    }();
    fwbuilder.settings_ = def;
    int serial = 0;
    //shoppingCart = shopCart.getCart();
    for_each(shopCart.getCart().begin(), shopCart.getCart().end(), [&shoppingFartJson, &serial](unique_ptr<BaseGoods>& up) {

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
//
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
        setMoney(root["money"].asDouble());
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
//
//
void Customer::balance()
{
    cout << "你现在还剩" << getMoney()<< "元钱，充值请输入8" << endl;
    int choice;
    cin >> choice;
    if (choice == 8)
    {
        cout << "请输入充值多少钱" << endl;
        double money;
        inputDouble(money);
        setMoney(getMoney() + money);
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
        return;
    }
}

bool Customer::buySomeThing(double price)
{
    if (price > getMoney())
    {
        cout << "抱歉，你的钱不够多" << endl;
        return false;
    }
    else
    {
        setMoney(getMoney() - price);
        cout << "已购买，你还剩" << getMoney()<< "这么多钱" << endl;
        return true;
    }
}

int Customer::getId()
{
    return id;
}
//
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
//
void Customer::minShoppingCart(Json::Value& goods, long long int last)
{
    shopCart.minShoppingCart(goods, last,getUsrName());
    //goods->setFreeze(goods->getFreeze()-last);
}

void Customer::showCart()
{
    shopCart.show();
}
//
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
//
double Customer::calShoppingCart()
{
    return shopCart.calShoppingCart();
}
//
//
void Customer::setAddress(string newAddress)
{
    Customer::storageAddress = newAddress;
}
//
string Customer::getAddress()
{
    return Customer::storageAddress;
}
//
////_finddata_t fileInfo;
////long handle = _findfirst(inPath.c_str(), &fileInfo);
////if (handle==-1)//todo: 异常处理
////{
////    std::cout << "此时还没有文件" << std::endl;
////    return false;
////}
////int finded = 0;
////do
////{
////    if ((tempUsr+".usr")==fileInfo.name)
////    {
////        finded = 1;
////        break;
////    }
////} while (!_findnext(handle,&fileInfo);
////_findclose(handle);
//
//Customer::~Customer()
//{
//}

