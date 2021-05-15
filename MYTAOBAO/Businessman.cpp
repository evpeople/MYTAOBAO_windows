#include "Businessman.h"


long long int Businessman::totalId = 0;
USRTYPE Businessman::type = USRTYPE::businessman;
std::string Businessman::storageAddress = ".";
using namespace std;
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
            cout<<busSGooods[0]->getDescription();
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

Businessman::Businessman(std::string name,std::string PassWd, vupOfBaseGoods& busSGooods, int goodsType)
    :BaseUsr{ name,PassWd }
{
    id = totalId;
    totalId++;
    this->goodsType = goodsType;
    this->busSGooods = std::move(busSGooods);
}

void Businessman::storage()
{
    Json::Value root, goods,goodsDiscount;
    Json::StreamWriterBuilder fwbuilder;
    static Json::Value def = []() {
        Json::Value def;
        Json::StreamWriterBuilder::setDefaults(&def);
        def["emitUTF8"] = true;
        return def;
    }();
    fwbuilder.settings_ = def;
    int serial = 0;
    for_each(busSGooods.begin(), busSGooods.end(), [&goods, &serial](unique_ptr<BaseGoods>& up) {

        goods[serial]["name"] = up->getName();
        goods[serial]["price"] = up->getPrice();
        goods[serial]["remain"] = up->getRemain();
        goods[serial]["type"] = up->getType();
        goods[serial]["description"] = up->getDescription();
        serial++;
        });
    root["usrID"] = id;
    root["usrName"] = getUsrName();
    root["usrPass"] = getUsrPassWord();
    root["usrType"] = "Businessman";
    root["goods"] = goods;
    root["goodsType"] = goodsType;
    goodsDiscount["Book"]=Book::getDiscount();
    goodsDiscount["Cloths"]=Cloths::getDiscount();
    goodsDiscount["EleProduct"]=EleProduct::getDiscount();
    root["goodDiscount"] = goodsDiscount;

    string outFile = Businessman::storageAddress + getUsrName() + ".usr";
    ofstream fout{ outFile ,ios_base::app };
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(root, &fout);
    fout.close();
}

bool Businessman::login(string tempUsr,string passWord)
{

    string inPath = Businessman::storageAddress + tempUsr + ".usr";

   
        //passWord = "evp";
        if (auth(passWord))
        {
            cout << "登陆成功" << endl;
            ifstream fin;
            fin.open(inPath);
            if (fin.is_open())
            {
                Json::CharReaderBuilder reader;
                JSONCPP_STRING errs;

                Json::Value root, goods;
                if (!Json::parseFromStream(reader, fin, &root, &errs))
                {
                    cout << errs << endl;
                }

                id = root["usrID"].asInt64();
                goodsType = root["goodsType"].asInt();
                setUsrName(root["usrName"].asString());
                setUsrPassWord(root["usrPass"].asString());
                Book::setDiscount(root["goodsDiscount"]["Book"].asDouble());
                Cloths::setDiscount(root["goodsDiscount"]["Cloths"].asDouble());
                EleProduct::setDiscount(root["goodsDiscount"]["EleProduct"].asDouble());
                goods = root["goods"];

                string name;
                double price;
                long long int remain;
                for (size_t i = 0; i < goods.size(); i++)
                {
                    if (goods[i]["type"].asString() == "Book")
                    {

                        busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ goods[i]["remain"].asInt64() ,goods[i]["price"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString() }));
                    }
                    else if (goods[i]["type"].asString() == "Cloths")
                    {
                        busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ goods[i]["remain"].asInt64() ,goods[i]["price"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString() }));

                    }
                    else if (goods[i]["type"].asString() == "EleProduct")
                    {
                        busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ goods[i]["remain"].asInt64() ,goods[i]["price"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString() }));
                    }
                    else
                    {
                        cout << "错误的文件" << goods[i].toStyledString() << endl;
                    }
                }
                fin.close();
            return true;
        }
        else
        {
            cout << "密码错误" << endl;
            return false;
        }
    }
    else
    {
        cout << "抱歉，此用户不存在！，请注册" << endl;
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


void Businessman::discount(int kind, double discount)
{
    enum class GOODS
    {
        BOOK = 0,
        ELEPRODUCT,
        CLOTHES
    };
    switch ((GOODS)kind)
    {
    case GOODS::BOOK:
        Book::setDiscount(discount);
        break;
    case GOODS::ELEPRODUCT:
        EleProduct::setDiscount(discount);
        break;
    case GOODS::CLOTHES:
        Cloths::setDiscount(discount);
        break;
    default:
        break;
    }
    this->storage();
}

void Businessman::setGoods()
{
}
