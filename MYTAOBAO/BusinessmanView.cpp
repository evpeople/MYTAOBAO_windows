#include "BusinessmanView.h"
#include"BusResultView.h"
#include"ViewManger.h"

using namespace std;

void BusinessmanView::show()
{
    showGoods();
    viewInput();
}

void BusinessmanView::viewInput()
{
    std::regex regexSec("[1234]");
    int choice;
    ViewManger& viewManger = ViewManger::getInstance();
    input(choice, "尊敬的商家\n1\t更改商品描述\n2\t更改商品价格\n3\t更改商品剩余量\n4\t新增商品\n", regexSec);
    string name;
    string ans;
    if (choice>0&&choice<4)
    {
        input(name, "输入更改的商品的名字");
    }
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, PRICE,LAST,NAME
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::DES:
        input(ans, "新描述是");
        for_each(temp.begin(), temp.end(), [ans, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setDescription(ans);
        }
        });   
        break;
    case CHOICEEVENT::NAME:
        addGoods(temp);
        break;
    case CHOICEEVENT::PRICE:
        cout << "新价格是" << endl;
        double newPrice;
        cin >> newPrice;
        for_each(temp.begin(), temp.end(), [newPrice, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setOriginalPrice(newPrice);
        }
        });   
        break;
    case CHOICEEVENT::LAST:
        cout << "新剩余量是" << endl;
        long long int newRemain;
        cin >> newRemain;
        for_each(temp.begin(), temp.end(), [newRemain, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setOriginalPrice(newRemain);
        }
        });  
        break;
    default:
        break;
    }
    Usr->storage();
    viewManger.setNext(make_unique<BusResultView>());
    

}

void BusinessmanView::addGoods(std::vector<std::unique_ptr<BaseGoods>>& tempVec)
{
    enum class GOODS
    {
        BOOK = 0,
        ELEPRODUCT,
        CLOTHES
    };
    bool in = true;
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
            tempVec.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "添加完毕" << endl;
            break;
        }
        case GOODS::CLOTHES:
        {
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
            tempVec.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "添加完毕" << endl;
            break;
        }
        case GOODS::ELEPRODUCT:
        {
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
            tempVec.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "添加完毕" << endl;
            break;
        }
        default:
            in = false;
            break;
        }
    }
}

bool BusinessmanView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
