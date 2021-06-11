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
    std::regex regexSec("[123456]");
    input(choice, "1\t向购物车增加商品\n2\t向购物车减少商品\n3\t计算购物车总额\n4\t展示购物车\n5\t支付订单\n6\t回到上一界面", regexSec);
    cin.get();
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "请输入增加的商品的名字,并在回车之后输入增加的数量");
        //cin.get();
        inputLLint(number);
        Usr->addInShoppingCart(GoodSearchFromName[name], number);
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MIN:
        input(name, "请输入减少的商品的名字，并在回车后输入减少的数量");
        //cin.get();
        inputLLint(number);
        Usr->minShoppingCart(GoodSearchFromName[name], number);
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
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
    case CHOICEEVENT::BUY://todo: 冻结减少应该在defaultGoods中体现，Bussine只用加钱和减少货物
        cout << "清空购物车" << endl;
        Usr->buyAllThing();
    viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
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
