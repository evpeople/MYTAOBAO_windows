#include "Customer.h"
#include<json/json.h>
#include <iostream>

long long int Customer::totalId = 0;
USRTYPE Customer::type = USRTYPE::customer;
Customer::Customer(std::string name, std::string PassWd):BaseUsr{ name, PassWd
}
{
    id = totalId;
    totalId++;
}

void Customer::storage()
{
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = id;

    temp["usrName"] = usrName;
    temp["usrPass"] = usrPassWord;//Ê¹ÓÃ¹þÏ£±í£¡
    auto enumToString = [this]()->string {switch (this->usrType) {
    case USRTYPE::customer:return "customer";
    case USRTYPE::businessman:return"businessman";
    case USRTYPE::newUsr: return "sd";
    }};
    temp["usrType"] = enumToString();
    //string out = temp.toStyledString();
    std::ofstream fout{ "ALL_USR.txt",std::ios_base::app };
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp, &fout);
    fout.close();
    return false;
}



Customer::~Customer()
{
    int a = 1;
}
