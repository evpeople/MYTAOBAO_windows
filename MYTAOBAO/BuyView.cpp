#include "BuyView.h"
#include"ViewManger.h"
#include"Views.h"

using namespace std;

void BuyView::show()
{
    showGoods();
    viewInput();
}

void BuyView::viewInput()
{
    string name, password;
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[12]");
    std::regex regexSec("[1234]");
    input(choice, "1\t查询货物种类\n2\t购买\n3\t购物车\n4\t放弃剁手", regexSec);
    enum class CHOICEEVENT
    {
        SEARCH=1,BUY,CART,GIVEUP
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::SEARCH:
        while (true)
        {
            
            search();
            input(choice, "1\t继续查找\n2\t结束查找", regexFir);
            if (choice==2)
            {
                break;
            }
        }
        viewManger.setNext(make_unique<CusResultView>());
        break;
    case CHOICEEVENT::GIVEUP:
        viewManger.setNext(make_unique<CusResultView>());
        break;
    case CHOICEEVENT::CART:
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::BUY:
        {
        Json::Value temp;
        string name;
        input(name, "你要购买的商品的名字");
        search(name, temp);
        if (temp)
        {
            if (!Usr->buySomeThing(temp["price"].asDouble()))
            {
                cout << "充钱吧亲";
            }
            Usr->storage();
            
        }
        viewManger.sleepMs(500);
        viewManger.setNext(make_unique<BuyView>());
        }
        break;
    default:
        viewManger.setNext(make_unique<FailureView>());
        break;
    }
}

bool BuyView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}

void BuyView::search()
{
    int choice;
    std::regex regexFir("[12]");
    input(choice, "1\t按照名称查询\n2\t按照类别查询\n", regexFir);
    cin.get();
    enum class CHOICEEVENT
    {
        NAME = 1, TYPE
    };
    string reg;
    switch ((CHOICEEVENT)(choice))
    {
    case CHOICEEVENT::NAME:
        input(reg, "要查找的物品的名字");
        cout << GoodSearchFromName[reg].toStyledString();
        break;
    case CHOICEEVENT::TYPE:
        input(reg, "输入货物类别");
        for (size_t i = 0; i < GoodSearchFromType[reg].size(); i++)
        {
            cout << GoodSearchFromType[reg][i].toStyledString();
            if (i&&i%5==0)
            {
                input(choice, "1\t继续输出\n2\t终止输出\n", regexFir);
                if (choice==2)
                {
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void BuyView::search(std::string name, Json::Value& ansGood)
{
    ansGood = GoodSearchFromName[name];
}

void BuyView::search(std::string, std::vector<Json::Value>& ansGoods)
{
}
