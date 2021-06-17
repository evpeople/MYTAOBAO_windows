#include "BuyView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Server.h"

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

    ViewManger& viewManger = ViewManger::getInstance(getId());
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
        input(name, "��Ҫ�������Ʒ������");
        search(name, temp);
        if (temp)
        {
            if (!Usr->buySomeThing(temp["price"].asDouble()))
            {
                send(Server::sockS[getId()], "000yyyyyy", 10, 0);
                cout << "��Ǯ����";
            }
            else
            {
                send(Server::sockS[getId()], "11111yyyy", 10, 0);
            }
            Usr->storage();
        }
        else
        {
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
    input(choice, "1\t�������Ʋ�ѯ\n2\t��������ѯ\n", regexFir);
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
        string x = GoodSearchFromName[reg].toStyledString();
        send(Server::sockS[getId()], x.c_str(), x.size(), 0);
        cout << x;
        break;
    }
    case CHOICEEVENT::TYPE:
    {
        input(reg, "����������");
        int size = GoodSearchFromType[reg].size();
        send(Server::sockS[getId()], to_string(size).c_str(), to_string(size).size(), 0);
        for (size_t i = 0; i < size; i++)
        {
            string x = GoodSearchFromType[reg][i].toStyledString();
            send(Server::sockS[getId()], x.c_str(), x.size(), 0);
            char y[20];
            recv(Server::sockS[getId()], y, 20, 0);
            cout << GoodSearchFromType[reg][i].toStyledString();

            if (i && i % 5 == 0)
            {
                input(choice, "1\t�������\n2\t��ֹ���\n", regexFir);
                if (choice == 2)
                {
                    break;
                }
            }
        }
        break;
    }default:
        break;
    }
}

void BuyView::search(std::string name, Json::Value& ansGood)
{
    ansGood = GoodSearchFromName[name];
    if (ansGood)
    {
        send(Server::sockS[getId()], ansGood.asCString(), ansGood.asString().size(), 0);
    }
    else
    {
        send(Server::sockS[getId()], "0yyyyyyyyy", 11, 0);
    }
}

void BuyView::search(std::string, std::vector<Json::Value>& ansGoods)
{
}