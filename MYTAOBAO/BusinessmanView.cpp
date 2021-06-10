#include "BusinessmanView.h"
#include"BusResultView.h"
#include"ViewManger.h"
#include<algorithm>

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
        cin.get();
        input(name, "输入更改的商品的名字");
    }
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, PRICE,LAST,NEWGOOD
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
    case CHOICEEVENT::NEWGOOD:
        addGoods(temp);
        break;
    case CHOICEEVENT::PRICE:
        cout << "新价格是" << endl;
        double newPrice;
        inputDouble(newPrice);
        int i;
        //for ( i = 0; i < temp.size(); i++)
        //{
        //    if (temp[i]->getName() == name)
        //    {
        //        temp[i]->setOriginalPrice(newPrice);
        //    }
        //}
        for_each(temp.begin(), temp.end(), [newPrice, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setOriginalPrice(newPrice);
            cout << "成功更改" << endl;
        }
        });   
        break;
    case CHOICEEVENT::LAST:
        cout << "新剩余量是" << endl;
        long long int newRemain;
        inputLLint(newRemain);
        for_each(temp.begin(), temp.end(), [newRemain, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setRemain(newRemain);
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
    Usr->addGoods();
}

bool BusinessmanView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
