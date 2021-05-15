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
    input(choice, "1\t以商人身份注册\n2\t以顾客身份注册\n", regexFir);

    while (true)
    {
        std::cout << "请输入用户名" << endl;
        cin >> name;
        if (isExist(name, choice))
        {
            cout << "此用户名已被占用，请您选择其他用户名" << endl;
            continue;
        }
        break;
    }

    cout << "请输入密码" << endl;
    cin >> password;
    while (true)
    {
        cout << "请输入密码" << endl;
        cin >> password;
        cout << "请再次确认您的密码" << endl;
        cin >> password2;
        if (password != password2)
        {
            cout << "两次密码不同，请重新注册" << endl;
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
        cout << "下面进入添加商品环节，小商人，你准备好了吗" << endl;
        while (in)
        {
   
            cout << "输入0，是贩卖书，输入1是贩卖电子产品，输入2是贩卖衣服,其余输入是退出商品添加" << endl;
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
                cout << "请输入书的名字" << endl;
                cin >> name;
                cout << "请输入" << name << "的价钱" << endl;
                cin >> price;
                cout << "请输入" << name << "的仓库存量" << endl;
                cin >> remain;
                cout << "请输入" << name << "的描述" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name,des }));
                cout << name << "添加完毕" << endl;
                break;
            }
            case GOODS::CLOTHES:
            {
                goodsType |= 2;
                string name;
                string des;
                double price;
                long long int remain;
                cout << "请输入衣服的名字" << endl;
                cin >> name;
                cout << "请输入" << name << "的价钱" << endl;
                cin >> price;
                cout << "请输入" << name << "的仓库存量" << endl;
                cin >> remain;
                cout << "请输入" << name << "的描述" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name,des }));
                cout << name << "添加完毕" << endl;
                break;
            }
            case GOODS::ELEPRODUCT:
            {
                goodsType |= 4;
                string name;
                string des;
                double price;
                long long int remain;

                cout << "请输入电子产品的名字" << endl;
                cin >> name;
                cout << "请输入" << name << "的价钱" << endl;
                cin >> price;
                cout << "请输入" << name << "的仓库存量" << endl;
                cin >> remain;
                cout << "请输入" << name << "的描述" << endl;
                cin >> des;
                busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name,des }));
                cout << name << "添加完毕" << endl;
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
        cout << "保存完毕" << endl;
        break;
    }
    case PEOPLETYPE::CUS:
    {
        double money;
        cout << "您想充值多少钱" << endl;
        cin >> money;
        //Customer temp{ name,pass,money };
        Usr = std::move(make_unique<Customer>(name, pass, money));
        Usr->storage();
        cout << "保存完毕" << endl;
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