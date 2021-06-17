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
    input(choice, "1\t���ﳵ������Ʒ\n2\t���ﳵ������Ʒ\n3\t���㹺�ﳵ�ܶ�\n4\tչʾ���ﳵ\n5\tֱ����չ��ﳵ(ͬʱ��Ǯ)\n6\t��չ��ﳵ������Ǯ\n7\t���ɶ���\n8\t�ص���һ����", regexSec);
    cin.get();
    enum class CHOICEEVENT
    {
        ADD= 1,MIN ,TOTAL, SHOW,BUY,CLEARCART,MAKE
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::ADD:
        input(name, "���������ӵ���Ʒ������");
        cout << "�������ӵ�����" << endl;
        BaseView::input(number);
        addGoods();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MIN:
        input(name, "��������ٵ���Ʒ�����֣����ڻس���������ٵ�����");
        //cin.get();
        minGoods();
        BaseView::input(number);
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::CLEARCART:
        cout << "���ù��ﳵ���" << endl;
        break;
    case CHOICEEVENT::TOTAL:
    {   
        char a[2001];
        int len = recv(Server::sockS, a, 2000, 0);
        a[len] = '\0';
        string x(a);
        cout << "�ܼ���" << x;
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
    }   
        break;
    case CHOICEEVENT::SHOW:
        cout << "���ﳵ������" << endl;
        showCart();

        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::BUY:
        cout << "��չ��ﳵ" << endl;
        buyAll();
        viewManger.sleepMs(250);
        viewManger.setNext(make_unique<CartView>());
        break;
    case CHOICEEVENT::MAKE:
        cout << "���ɶ���" << endl;
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
