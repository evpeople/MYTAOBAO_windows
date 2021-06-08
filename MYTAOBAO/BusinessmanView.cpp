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
    input(choice, "�𾴵��̼�\n1\t������Ʒ����\n2\t������Ʒ�۸�\n3\t������Ʒʣ����\n4\t\n", regexSec);
    string name;
    string ans;
    input(name, "������ĵ���Ʒ������");
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, NAME, PRICE,LAST
    };
    switch ((CHOICEEVENT)choice)
    {
    case CHOICEEVENT::DES:
        input(ans, "��������");
        for_each(temp.begin(), temp.end(), [ans, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setDescription(ans);
        }
        });   
        break;
    case CHOICEEVENT::NAME:
        input(ans, "��������");
        for_each(temp.begin(), temp.end(), [ans, name](unique_ptr<BaseGoods>& up) {
        if (up->getName() == name)
        {
            up->setName(ans);
        }
        });        
        break;
    case CHOICEEVENT::PRICE:
        cout << "�¼۸���" << endl;
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
        cout << "��ʣ������" << endl;
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
