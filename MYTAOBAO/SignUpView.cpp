#include "SignUpView.h"
#include"ViewManger.h"
#include"Views.h"
#include"Goods.h"
#include<iostream>
using namespace std;
enum class PEOPLETYPE
{
    BUS = 1, CUS = 2
};
void SignUpView::show()
{
    showGoods();
    viewInput();
}

void SignUpView::viewInput()
{
    string name, password, password2;
    int choice;

    ViewManger& viewManger = ViewManger::getInstance();
    std::regex regexFir("[12]");
    input(choice, "1\t���������ע��\n2\t�Թ˿����ע��\n", regexFir);

    while (true)
    {
        std::cout << "�������û���" << endl;
        cin >> name;
        if (isExist(name, choice))
        {
            cout << "���û����ѱ�ռ�ã�����ѡ�������û���" << endl;
            continue;
        }
        break;
    }

    cout << "����������" << endl;
    cin >> password;
    while (true)
    {
        cout << "����������" << endl;
        cin >> password;
        cout << "���ٴ�ȷ����������" << endl;
        cin >> password2;
        if (password != password2)
        {
            cout << "�������벻ͬ��������ע��" << endl;
            continue;
        }
        break;
    }

    dealInput(name, password, choice);
    viewManger.setNext(make_unique<MainView>());
}

bool SignUpView::dealInput(std::string name, std::string pass, int choice)
{
    switch ((PEOPLETYPE)choice)
    {
    case PEOPLETYPE::BUS:
    {
        std::vector<std::unique_ptr<BaseGoods>>  busSGooods;
        enum class GOODS
        {
            BOOK = 0,
            ELEPRODUCT,
            CLOTHES
        };
       
        int goodsType = 8;
        bool in = true;
        cout << "������������Ʒ���ڣ�С���ˣ���׼��������" << endl;
        while (in)
        {
   
            cout << "����0���Ƿ����飬����1�Ƿ������Ӳ�Ʒ������2�Ƿ����·�,�����������˳���Ʒ���" << endl;
            int temp;
            cin >> temp;
            cin.clear();
            cin.ignore();
            switch ((GOODS)temp)
            {
            case GOODS::BOOK:
            {
                goodsType |= 1;
                string name;
                string des;
                double price;
                long long int remain;
                cout << "�������������" << endl;
                cin >> name;
                cout << "������" << name << "�ļ�Ǯ" << endl;
                cin >> price;
                cout << "������" << name << "�Ĳֿ����" << endl;
                cin >> remain;
                cout << "������" << name << "������" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name,des }));
                cout << name << "������" << endl;
                break;
            }
            case GOODS::CLOTHES:
            {
                goodsType |= 2;
                string name;
                string des;
                double price;
                long long int remain;
                cout << "�������·�������" << endl;
                cin >> name;
                cout << "������" << name << "�ļ�Ǯ" << endl;
                cin >> price;
                cout << "������" << name << "�Ĳֿ����" << endl;
                cin >> remain;
                cout << "������" << name << "������" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name,des }));
                cout << name << "������" << endl;
                break;
            }
            case GOODS::ELEPRODUCT:
            {
                goodsType |= 4;
                string name;
                string des;
                double price;
                long long int remain;

                cout << "��������Ӳ�Ʒ������" << endl;
                cin >> name;
                cout << "������" << name << "�ļ�Ǯ" << endl;
                cin >> price;
                cout << "������" << name << "�Ĳֿ����" << endl;
                cin >> remain;
                cout << "������" << name << "������" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name,des }));
                cout << name << "������" << endl;
                cout << busSGooods[0]->getDescription();
                break;
            }
            default:
                in = false;
                break;
            }
        }
        
        //(**Usr) = Businessman{ name,pass,busSGooods,goodsType };
        //(*Usr)->storage();
        Usr = std::move(make_unique<Businessman>(name, pass, busSGooods, goodsType));
        Usr->storage();
        cout << "�������" << endl;
        break;
    }
    case PEOPLETYPE::CUS:
    {
        double money;
        cout << "�����ֵ����Ǯ" << endl;
        cin >> money;
        //Customer temp{ name,pass,money };
        Usr = std::move(make_unique<Customer>(name, pass, money));
        Usr->storage();
        cout << "�������" << endl;
        break;
    }
    default:
        break;
    }
    return true;
}

bool SignUpView::isExist(string name, int choice)
{
    string inPath;
    ifstream fin;
    switch ((PEOPLETYPE)choice)
    {
    case PEOPLETYPE::BUS:
        inPath = Businessman::getAddress() + name + ".usr";
        fin.open(inPath);
        if (fin.is_open())
        {
            fin.close();
            return true;
        }
        else
        {
            return false;
        }
        break;
    case PEOPLETYPE::CUS:
        inPath = Customer::getAddress() + name + ".usr";
        fin.open(inPath);
        if (fin.is_open())
        {
            fin.close();
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        break;
    }
}