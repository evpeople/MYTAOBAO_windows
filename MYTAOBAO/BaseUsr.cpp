#include "BaseUsr.h"
#include<iostream>
#include<fstream>
#include <openssl/sha.h>
#include<json/json.h>
//long long int BaseUsr::totalNum = 0;
auto enumToString = [](USRTYPE a)->string {switch (a) {
case USRTYPE::customer:return "customer";
case USRTYPE::businessman:return"businessman";
case USRTYPE::newUsr: return "sd";
}};
void BaseUsr::storage()
{
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = usrId;

    temp["usrName"] = usrName;
    temp["usrPass"] = usrPassWord;
    temp["usrType"] = enumToString(usrType);
    //string out = temp.toStyledString();
    ofstream fout{"ALL_USR.txt",ios_base::app};
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp,&fout);
    fout.close();
}

bool BaseUsr::auth(string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    ostringstream e;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        e.put(hash[i]);
    }
    string en_passwd = e.str();
    return usrPassWord==en_passwd;
}

string BaseUsr::encryp(const string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    ostringstream e;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        e.put(hash[i]);
    }
    string en_passwd = e.str();
    return en_passwd;
}

string BaseUsr::tosting()
{
    std::cout << "ID:   " << usrId << "\nName:  " << usrName << "\nType:    " << enumToString(usrType) <<"\npd"<<usrPassWord<< std::endl;
    return string();
}

BaseUsr::BaseUsr()
{
    usrId = 0;
    usrName = "new_usr";
    usrPassWord = "0";
    usrType = USRTYPE::newUsr;
    isLogin = false;
}
BaseUsr::BaseUsr(string name, string pd)
{
    usrId = BaseUsr::totalNum;
    usrName = name;
    usrPassWord = encryp(pd);
    usrType = USRTYPE::newUsr;
    isLogin = true;
    BaseUsr::totalNum++;
}
BaseUsr::~BaseUsr()
{}
