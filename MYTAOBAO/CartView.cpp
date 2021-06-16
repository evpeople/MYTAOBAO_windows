#include "CartView.h"
#include"Views.h"
#include"ViewManger.h"

using namespace std;
void CartView::show()
{
    showGoods();
    viewInput();
}

void CartView::viewInput()
{
    string name;
    int choice;
    long long int number;
    Json::Value temp;
    ViewManger& viewManger = ViewManger::getInstance();
    //std::regex regexFir("[12]");
    std::regex regexSec("[12345678]");
    input(choice, "1\t向购物车增加商品\n2\t向购物车减少商品\n3\t计算购物车总额\n4\t展示购物车\n5\t直接清空购物车(同时付钱)\n6\t清空购物车，不付钱\n7\t生成订单\n8\t回到上一界面", regexSec);
    cin.get();
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY,CLEARCART,MAKE
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "请输入增加的商品的名字,并在回车之后输入增加的数量");
        //cin.get();
        BaseView::input(number);
        Usr->addInShoppingCart(GoodSearchFromName[name], number);//todo:添加成功，不能再次读取到，不能通过其计算结果，不能锁住(没有做锁的逻辑)
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MIN:
        input(name, "请输入减少的商品的名字，并在回车后输入减少的数量");
        //cin.get();
        BaseView::input(number);
        Usr->minShoppingCart(GoodSearchFromName[name], number);
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::CLEARCART:
        cout << "清空完成" << endl;
        Usr->clearAllShopCart();
         //todo: 文件保存覆盖（）freeze的debug
        break;
    case CHOICEEVENT::TOTAL:
        cout << "总价是" << Usr->calShoppingCart();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::SHOW:
        cout << "购物车的详情" << endl;
        Usr->showCart();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::BUY:
        cout << "清空购物车" << endl;
        Usr->buyAllThing();
        Usr->storage();
    viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MAKE:
        cout << "生成订单" << endl;
        viewManger.setNext(make_unique<MakeBillView>());
        //todo: 生成订单冻结操作的debug。
        break;
    default:
        viewManger.setNext(make_unique<BuyView>());
        break;
    }
}

bool CartView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}

bool CartView::dealBuy()
{
    return false;
}

void CartView::search(std::string name, Json::Value& ansGood)
{
    ansGood = GoodSearchFromName[name];
}
