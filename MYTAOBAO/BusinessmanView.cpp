#include "BusinessmanView.h"
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
    input(choice, "尊敬的商家\n1\t更改商品描述\n2\t更改商品价格\n3\t更改商品剩余量\n4\t\n", regexSec);
    string name;
    string ans;
    input(name, "输入更改的商品的名字");
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, NAME, PRICE,LAST
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
        input(ans, "新名字是");
        for_each(temp.begin(), temp.end(), [ans, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setName(ans);
        }
        });        
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
    


}

bool BusinessmanView::dealInput(std::string name, std::string pass, int choice)
{
    return false;
}
