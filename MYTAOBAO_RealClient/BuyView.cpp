#include "BuyView.h"
#include"ViewManger.h"
#include"Server.h"
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
    input(choice, "1\t��ѯ��������\n2\t����\n3\t���ﳵ\n4\t��������", regexSec);
    enum class CHOICEEVENT
    {
        SEARCH = 1, BUY, CART, GIVEUP
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::SEARCH:
        while (true)
        {
            search();
            input(choice, "1\t��������\n2\t��������", regexFir);
            if (choice == 2)
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
        cin.get();
        input(name, "��Ҫ�������Ʒ������");
        if (buy())
        {
            cout << "����ɹ�" << endl;
        }
        else
        {
            cout << "��Ǯ����";
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
    char a[10001];
    input(choice, "1\t�������Ʋ�ѯ\n2\t��������ѯ\n", regexFir);
    cin.get();
    enum class CHOICEEVENT
    {
        NAME = 1, TYPE
    };
    string reg;
    switch ((CHOICEEVENT)(choice))
    {
    case CHOICEEVENT::NAME:
    {
        input(reg, "Ҫ���ҵ���Ʒ������");
        int len = recv(Server::sockS, a, 10000, 0);
        a[len] = '\0';//����json
        string x(a);
        cout << x;
        break;
    }
    case CHOICEEVENT::TYPE:
    {
        input(reg, "����������");
        char b[61];
        int x = recv(Server::sockS, b, 50, 0);
        b[x] = '\0';
        string p(b);
        int size = stol(p, nullptr);
        for (size_t i = 0; i < size; i++)
        {
            int len = recv(Server::sockS, a, 10000, 0);
            a[len] = '\0';//����json
            string x(a);
            cout << x;
            send(Server::sockS, "2", 1, 0);

            cout << x;
            if (i && i % 5 == 0)
            {
                input(choice, "1\t�������\n2\t��ֹ���\n", regexFir);
                if (choice == 2)
                {
                    break;
                }
            }
        }
    }
    break;
    default:
        break;
    }
}

bool BuyView::buy()
{
    char a[20];
    int len = recv(Server::sockS, a, 20, 0);
    a[len] = '\0';
    if (a[0] == '0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void BuyView::search(std::string name, Json::Value& ansGood)
{
    char x[31];
    int len = recv(Server::sockS, x, 30, 0);
    x[len] = '\0';

    if (x[0] - '0' == 0 && x[1] == 'y')
    {
        ansGood = NULL;
        return;
    }
    string a(x);
    Json::Value e(a);

    ansGood = e;
}

void BuyView::search(std::string, std::vector<Json::Value>& ansGoods)
{
}