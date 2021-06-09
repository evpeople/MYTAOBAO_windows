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
    input(choice, "�𾴵��̼�\n1\t������Ʒ����\n2\t������Ʒ�۸�\n3\t������Ʒʣ����\n4\t������Ʒ\n", regexSec);
    string name;
    string ans;
    if (choice>0&&choice<4)
    {
        input(name, "������ĵ���Ʒ������");
    }
    std::vector<std::unique_ptr<BaseGoods>>& temp= Usr->getGoods();
    enum class CHOICEEVENT
    {
        DES= 1, PRICE,LAST,NAME
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
        addGoods(temp);
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
        cout << "����0���Ƿ����飬����1�Ƿ������Ӳ�Ʒ������2�Ƿ����·�,�����������˳���Ʒ���" << endl;
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
            cout << "�������������" << endl;
            cin >> name;
            cout << "������" << name << "�ļ�Ǯ" << endl;
            cin >> price;
            cout << "������" << name << "�Ĳֿ����" << endl;
            cin >> remain;
            cout << "������" << name << "������" << endl;
            cin >> des;
            tempVec.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "������" << endl;
            break;
        }
        case GOODS::CLOTHES:
        {
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
            tempVec.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "������" << endl;
            break;
        }
        case GOODS::ELEPRODUCT:
        {
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
            tempVec.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name,des,Usr->getUsrName() }));
            cout << name << "������" << endl;
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
