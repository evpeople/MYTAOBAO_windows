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
    input(choice, "1\t���ﳵ������Ʒ\n2\t���ﳵ������Ʒ\n3\t���㹺�ﳵ�ܶ�\n4\tչʾ���ﳵ\n5\tֱ����չ��ﳵ(ͬʱ��Ǯ)\n6\t��չ��ﳵ������Ǯ\n7\t���ɶ���\n8\t�ص���һ����", regexSec);
    cin.get();
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY,CLEARCART,MAKE
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "���������ӵ���Ʒ������,���ڻس�֮���������ӵ�����");
        //cin.get();
        BaseView::input(number);
        Usr->addInShoppingCart(GoodSearchFromName[name], number);//todo:��ӳɹ��������ٴζ�ȡ��������ͨ�����������������ס(û���������߼�)
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MIN:
        input(name, "��������ٵ���Ʒ�����֣����ڻس���������ٵ�����");
        //cin.get();
        BaseView::input(number);
        Usr->minShoppingCart(GoodSearchFromName[name], number);
        Usr->storage();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::CLEARCART:
        cout << "������" << endl;
        Usr->clearAllShopCart();
         //todo: �ļ����渲�ǣ���freeze��debug
        break;
    case CHOICEEVENT::TOTAL:
        cout << "�ܼ���" << Usr->calShoppingCart();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::SHOW:
        cout << "���ﳵ������" << endl;
        Usr->showCart();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::BUY:
        cout << "��չ��ﳵ" << endl;
        Usr->buyAllThing();
        Usr->storage();
    viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MAKE:
        cout << "���ɶ���" << endl;
        viewManger.setNext(make_unique<MakeBillView>());
        //todo: ���ɶ������������debug��
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
