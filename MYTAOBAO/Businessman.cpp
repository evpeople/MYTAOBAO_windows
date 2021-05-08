#include "Businessman.h"
using namespace std;


long long int Businessman::totalId = 0;
USRTYPE Businessman::type = USRTYPE::businessman;
string Businessman::storageAddress = ".";
Businessman::Businessman(std::string name, std::string PassWd)
    :BaseUsr{name,PassWd}
{
    enum class GOODS
    {
        BOOK=0,
        ELEPRODUCT,
        CLOTHES
    };
    id = totalId;
    totalId++;
    goodsType = 8;
    bool in = true;
    cout << "������������Ʒ���ڣ�С���ˣ���׼��������,����0���Ƿ����飬����1�Ƿ������Ӳ�Ʒ������2�Ƿ����·�,�����������˳���Ʒ���" << endl;
    while (in)
    {
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
            double price;
            long long int remain;
            cout << "�������������" << endl;
            cin >> name;
            cout << "������" << name << "�ļ�Ǯ" << endl;
            cin >> price;
            cout << "������" << name << "�Ĳֿ����" << endl;
            cin >> remain;
            busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name }));
            break;
        }
        case GOODS::CLOTHES:
        {
            goodsType |= 2;
            string name;
            double price;
            long long int remain;
            cout << "�������������" << endl;
            cin >> name;
            cout << "������" << name << "�ļ�Ǯ" << endl;
            cin >> price;
            cout << "������" << name << "�Ĳֿ����" << endl;
            cin >> remain;
            busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name }));
            break;
        }
        case GOODS::ELEPRODUCT:
        {
            goodsType |= 4;
            string name;
            double price;
            long long int remain;
            cout << "�������������" << endl;
            cin >> name;
            cout << "������" << name << "�ļ�Ǯ" << endl;
            cin >> price;
            cout << "������" << name << "�Ĳֿ����" << endl;
            cin >> remain;
            busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name }));
            break;
        }
        default:
            in = false;
            break;
        }
    }
   

}

Businessman::Businessman()
    :BaseUsr("0","0")
{
    id = 0;
    goodsType = 0;
}

void Businessman::storage()
{
    Json::Value root, goods;
    Json::StreamWriterBuilder fwbuilder;
    int serial = 0;
    for_each(busSGooods.begin(), busSGooods.end(), [&goods, &serial](unique_ptr<BaseGoods>& up) {

        goods[serial]["name"] = up.get()->getName();
        goods[serial]["price"] = up.get()->getPrice();
        goods[serial]["remain"] = up.get()->getRemain();
        serial++;
        });
    root["usrID"] = id;
    root["usrName"] = getUsrName();
    root["usrPass"] = getUsrPassWord();
    root["usrType"] = "Businessman";
    root["goods"] = goods;
    root["goodsType"] = goodsType;
    string outFile = Businessman::storageAddress + getUsrName() + ".usr";
    ofstream fout{ outFile ,ios_base::app };
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(root, &fout);
    fout.close();
}

bool Businessman::login()
{
    cout << "�����������û���" << endl;
    string tempUsr;
    cin >> tempUsr;

    string inPath = Businessman::storageAddress + tempUsr + ".usr";

    ifstream fin;
    fin.open(inPath);
    if (fin.is_open())
    {
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;

        Json::Value root,goods;
        if (!Json::parseFromStream(reader, fin, &root, &errs))
        {
            cout << errs << endl;
        }

        id = root["usrID"].asInt64();
        goodsType = root["goodsType"].asInt();
        setUsrName(root["usrName"].asString());
        setUsrPassWord(root["usrPass"].asString());

        goods = root["goods"];

        string name;
        double price;
        long long int remain;
        for (size_t i = 0; i < goods.size(); i++)
        {
            busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ goods[i]["remain"].asInt64() ,goods[i]["price"].asDouble(),goods[i]["name"].asString() }));
        }
        fin.close();
        cout << "��������������" << endl;
        string passWord;
        cin >> passWord;
        //passWord = "evp";
        if (auth(passWord))
        {
            cout << "��½�ɹ�" << endl;
            return true;
        }
        else
        {
            cout << "�������" << endl;
            return false;
        }
    }
    else
    {
        cout << "��Ǹ�����û������ڣ�����ע��" << endl;
    }
    return false;
}

USRTYPE Businessman::getType()
{
    return Businessman::type;
}

void Businessman::setAddress(std::string newAddress)
{
    Businessman::storageAddress = newAddress;
}

std::string Businessman::getAddress()
{
    return Businessman::storageAddress;
}


void Businessman::discount()
{
}

void Businessman::setGoods()
{
}
