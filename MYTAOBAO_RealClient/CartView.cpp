#include "CartView.h"
#include"Views.h"
#include"ViewManger.h"
#include"Server.h"

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
        input(name, "请输入增加的商品的名字");
        cout << "输入增加的数量" << endl;
        BaseView::input(number);
        addGoods();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MIN:
        input(name, "请输入减少的商品的名字，并在回车后输入减少的数量");
        //cin.get();
        minGoods();
        BaseView::input(number);
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::CLEARCART:
        cout << "重置购物车完成" << endl;
        break;
    case CHOICEEVENT::TOTAL:
    {   
        char a[2001];
        int len = recv(Server::sockS, a, 2000, 0);
        a[len] = '\0';
        string x(a);
        cout << "总价是" << x;
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
    }   
        break;
    case CHOICEEVENT::SHOW:
        cout << "购物车的详情" << endl;
        showCart();

        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::BUY:
        cout << "清空购物车" << endl;
        buyAll();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MAKE:
        cout << "生成订单" << endl;
        viewManger.setNext(make_unique<MakeBillView>());
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


void CartView::showCart()
{
    char a[2001];
    int len=recv(Server::sockS, a, 2000, 0);
    a[len] = '\0';
    string x(a);
    cout << x;
    send(Server::sockS, "121221", 7, 0);
}

void CartView::buyAll()
{
    char a[31];
    int len=recv(Server::sockS, a, 30, 0);
    a[len] = '\0';
    string x(a);
    cout << x<<endl;
}

void CartView::addGoods()
{
    char a[21];
    int len=recv(Server::sockS, a, 20, 0);
    a[len] = '\0';
    string x(a);
    cout << x << endl;
}

void CartView::minGoods()
{
    char a[21];
    int len = recv(Server::sockS, a, 20, 0);
    a[len] = '\0';
    string x(a);
    cout << x << endl;
}

bool CartView::dealBuy()
{
    return false;
}

void CartView::search(std::string name, Json::Value& ansGood)
{
    ansGood = GoodSearchFromName[name];
}
