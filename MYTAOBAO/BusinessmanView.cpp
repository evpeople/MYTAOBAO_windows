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
    input(choice, "�𾴵��̼�\n1\t������Ʒ����\n2\t������Ʒ�۸�\n3\t������Ʒʣ����\n4\t������Ʒ\n", regexSec);
    string name;
    string ans;
    if (choice>0&&choice<4)
    {
        cin.get();
        input(name, "������ĵ���Ʒ������");
    }
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, PRICE,LAST,NEWGOOD
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
    case CHOICEEVENT::NEWGOOD:
        addGoods(temp);
        break;
    case CHOICEEVENT::PRICE:
        cout << "�¼۸���" << endl;
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
            cout << "�ɹ�����" << endl;
        }
        });   
        break;
    case CHOICEEVENT::LAST:
        cout << "��ʣ������" << endl;
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
