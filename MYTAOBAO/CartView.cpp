#include "CartView.h"
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
    int number;
    Json::Value temp;
    ViewManger& viewManger = ViewManger::getInstance();
    //std::regex regexFir("[12]");
    std::regex regexSec("[12345]");
    input(choice, "1\t向购物车增加商品\n2\t向购物车减少商品\n3\t计算购物车总额\n4\t展示购物车\n5\t支付订单", regexSec);
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "请输入增加的商品的名字,并在回车之后输入增加的数量");
        cin >> number;
        Usr->addInShoppingCart(GoodSearchFromName[name], number);
        break;
    case CHOICEEVENT::MIN:
        input(name, "请输入减少的商品的名字，并在回车后输入减少的数量");
        cin >> number;
        Usr->minShoppingCart(GoodSearchFromName[name], number);
        break;
    case CHOICEEVENT::TOTAL:
        cout << "总价是" << Usr->calShoppingCart();
        break;
    case CHOICEEVENT::SHOW:
        Usr->showCart();
        break;
    case CHOICEEVENT::BUY:
        Usr->
        break;
    default:
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
