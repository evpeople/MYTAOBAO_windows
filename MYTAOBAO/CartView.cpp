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
    input(choice, "1\t���ﳵ������Ʒ\n2\t���ﳵ������Ʒ\n3\t���㹺�ﳵ�ܶ�\n4\tչʾ���ﳵ\n5\t֧������", regexSec);
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "���������ӵ���Ʒ������,���ڻس�֮���������ӵ�����");
        cin >> number;
        Usr->addInShoppingCart(GoodSearchFromName[name], number);
        break;
    case CHOICEEVENT::MIN:
        input(name, "��������ٵ���Ʒ�����֣����ڻس���������ٵ�����");
        cin >> number;
        Usr->minShoppingCart(GoodSearchFromName[name], number);
        break;
    case CHOICEEVENT::TOTAL:
        cout << "�ܼ���" << Usr->calShoppingCart();
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
