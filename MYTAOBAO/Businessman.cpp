#include "Businessman.h"
#include"BaseView.h"

long long int Businessman::totalId = 0;
USRTYPE Businessman::type = USRTYPE::businessman;
std::string Businessman::storageAddress = ".";
using namespace std;
Businessman::Businessman(std::string name, std::string PassWd)
    :BaseUsr{name,PassWd}
{
    id = totalId;
    totalId++;
    goodsType = 8;
    setMoney(0);
}

Businessman::Businessman()
    :BaseUsr("0","0")
{
    id = 0;
    goodsType = 0;
    setMoney(0);
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
        goods[serial]["orginPrice"] = up->getOriginalPrice();
        goods[serial]["price"] = up->getPrice();
        goods[serial]["remain"] = up->getRemain();
        goods[serial]["type"] = up->getType();
        goods[serial]["description"] = up->getDescription();
        goods[serial]["owner"] = up->getOwner();
        goods[serial]["isFreeze"] = up->getFreeze();
        serial++;
        });
    root["money"] = getMoney();
    root["usrID"] = id;
    root["usrName"] = getUsrName();
    root["usrPass"] = getUsrPassWord();
    root["usrType"] = "Businessman";
    root["goods"] = goods;
    root["goodsType"] = goodsType;
    goodsDiscount["Book"]=Book::getDiscount();
    //cout << Book::getDiscount()<<getUsrName() << endl;
    goodsDiscount["Cloths"]=Cloths::getDiscount();
    goodsDiscount["EleProduct"]=EleProduct::getDiscount();
    root["goodDiscount"] = goodsDiscount;

    string outFile = Businessman::storageAddress + getUsrName() + ".usr";
    ofstream fout{ outFile ,ios_base::out };
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(root, &fout);
    fout.close();
    
    if (1)
    {
        string outFileGoods = "./baseFile/goodsFile/defalutGoods.json";

        fstream foutGoods;
        foutGoods.open(outFileGoods, ios_base::in);
        if (foutGoods.is_open())
        {
            Json::CharReaderBuilder reader;
            JSONCPP_STRING errs;

            Json::Value root;
            if (!Json::parseFromStream(reader, foutGoods, &root, &errs))
            {
                cout << errs << endl;
            }
            //for (size_t i = 0; i < root["goods"].size(); i++)
            //{
            //    root["goods"].append(Json::Value(root["goods"][i]));
            //}
            //root["goods"] = root["goods"];
            //cout << root["goods"].toStyledString()<<endl;
            foutGoods.close();
            foutGoods.open(outFileGoods, ios_base::out);
            for (size_t i = 0; i < goods.size(); i++)
            {
              root["goods"].append(Json::Value(goods[i]));
            }

            //cout << root["goods"].toStyledString();

           
 
            auto jsonWriterGoods(fwbuilder.newStreamWriter());
            jsonWriterGoods->write(root, &foutGoods);
            foutGoods.close();
        }
        else
        {
            cout << "没打开" << endl;
        }
    }
}

bool Businessman::loginWithoutChecked(std::string tempUsr)
{
    string inPath = Businessman::storageAddress + tempUsr + ".usr";
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
        setUsrPassWord(root["usrPass"].asString());
        //passWord = "evp";

             setMoney(root["money"].asDouble());
                 id = root["usrID"].asInt64();
            goodsType = root["goodsType"].asInt();
            setUsrName(root["usrName"].asString());
            setUsrPassWord(root["usrPass"].asString());
            Book::setDiscount(root["goodDiscount"]["Book"].asDouble());
            Cloths::setDiscount(root["goodDiscount"]["Cloths"].asDouble());
            EleProduct::setDiscount(root["goodDiscount"]["EleProduct"].asDouble());
            goods = root["goods"];

            for (size_t i = 0; i < goods.size(); i++)
            {
                if (goods[i]["type"].asString() == "Book")
                {

                    busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));
                }
                else if (goods[i]["type"].asString() == "Cloths")
                {
                    busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));

                }
                else if (goods[i]["type"].asString() == "EleProduct")
                {
                    busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));
                }
                else
                {
                    cout << "错误的文件" << goods[i].toStyledString() << endl;
                }
            }
            fin.close();
            return true;
        }
    return false;
}

bool Businessman::login(string tempUsr,string passWord)
{
    isLogin = true;
    string inPath = Businessman::storageAddress + tempUsr + ".usr";
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
        setUsrPassWord(root["usrPass"].asString());
        //passWord = "evp";
        if (auth(passWord))
        {
            cout << "登陆成功" << endl;


                id = root["usrID"].asInt64();
                goodsType = root["goodsType"].asInt();
                setUsrName(root["usrName"].asString());
                setUsrPassWord(root["usrPass"].asString());
                setMoney(root["money"].asDouble());
                Book::setDiscount(root["goodDiscount"]["Book"].asDouble());
                Cloths::setDiscount(root["goodDiscount"]["Cloths"].asDouble());
                EleProduct::setDiscount(root["goodDiscount"]["EleProduct"].asDouble());
                goods = root["goods"];

                string name;
                for (size_t i = 0; i < goods.size(); i++)
                {
                    if (goods[i]["type"].asString() == "Book")
                    {

                        busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));
                    }
                    else if (goods[i]["type"].asString() == "Cloths")
                    {
                        busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));

                    }
                    else if (goods[i]["type"].asString() == "EleProduct")
                    {
                        busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ goods[i]["remain"].asInt64() ,goods[i]["orginPrice"].asDouble(),goods[i]["name"].asString(),goods[i]["description"].asString(),getUsrName() }));
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

void Businessman::addGoods()
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
        long long int temp;
        inputLLint(temp);
        cin.get();
        switch ((GOODS)temp)
        {
        case GOODS::BOOK:
        {
            string name;
            string des;
            double price;
            long long int remain;
            cout << "请输入书的名字" << endl;
            getline(cin, name);
            cout << "请输入" << name << "的价钱" << endl;
            inputDouble(price);
            cout << "请输入" << name << "的仓库存量" << endl;
            inputLLint(remain);
            cout << "请输入" << name << "的描述" << endl;
            cin.get();
            getline(cin, des);
            busSGooods.push_back(unique_ptr<BaseGoods>(new Book{ remain,price,name,des,getUsrName() }));
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
            getline(cin, name);
            cout << "请输入" << name << "的价钱" << endl;
            inputDouble(price);
            cout << "请输入" << name << "的仓库存量" << endl;
            inputLLint(remain);
            cout << "请输入" << name << "的描述" << endl;
            cin.get();
            getline(cin, des);
            busSGooods.push_back(unique_ptr<BaseGoods>(new Cloths{ remain,price,name,des,getUsrName() }));
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
            cin.get();
            getline(cin, name);
            cout << "请输入" << name << "的价钱" << endl;
            inputDouble(price);
            cout << "请输入" << name << "的仓库存量" << endl;
            inputLLint(remain);
            cout << "请输入" << name << "的描述" << endl;
            cin.get();
            getline(cin, des);
            busSGooods.push_back(unique_ptr<BaseGoods>(new EleProduct{ remain,price,name,des,getUsrName() }));
            cout << name << "添加完毕" << endl;
            //cout << busSGooods[0]->getDescription();
            break;
        }
        default:
            in = false;
            break;
        }
    }
}

USRTYPE Businessman::getType()
{
    return Businessman::type;
}

void Businessman::setAddress(std::string newAddress)
{
    Businessman::storageAddress = newAddress;
}

void Businessman::dealBuy(string goodsName, long long int goodsNum)
{
    size_t i = 0;
    for ( i = 0; i < busSGooods.size(); i++)
    {
        if (busSGooods[i]->getName() == goodsName)
        {
            double money = busSGooods[i]->getPrice()*goodsNum;//下面这步非常重要，因为要统一保存。
            if ((busSGooods[i]->getRemain() - goodsNum)<0)
            {
                cout << "支付失败，此商人当前的剩余量不足" << endl;
                return;
            }
            busSGooods[i]->setRemain(busSGooods[i]->getRemain() - goodsNum);//此步可有可无，实际上有用的是defalut的内容。
            setMoney(getMoney() + money);
            break;
        }
    }
    storage();
}

std::string Businessman::getAddress()
{
    return Businessman::storageAddress;
}


void Businessman::discount(int kind, double discount)
{
    enum class GOODS
    {
        BOOK = 1,
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

vupOfBaseGoods& Businessman::getGoods()
{
    return busSGooods;
}

void Businessman::setGoodsFreeze(std::string goodsName,long long int freeNum)
{
    size_t i = 0;
    for (i = 0; i < busSGooods.size(); i++)
    {
        if (busSGooods[i]->getName() == goodsName)
        {
            if ((busSGooods[i]->getRemain() - freeNum)  <= 0)
            {
                cout << "冻结失败，此商人当前的剩余量不足" << endl;
                return;
            }
            busSGooods[i]->setFreeze(busSGooods[i]->getFreeze() +freeNum);
            break;
        }
    }
    storage();
}





