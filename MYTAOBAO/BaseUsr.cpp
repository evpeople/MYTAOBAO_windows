#include "BaseUsr.h"
#include<iostream>
#include<fstream>
#include <openssl/sha.h>
#include<json/json.h>
void BaseUsr::discount()
{
    std::cout << "只有商家可以打折" << std::endl;
}
bool BaseUsr::changePassWord()
{
    std::cout << "请输入你原本的密码" << std::endl;
    std::string pass;
    std::cin >> pass;
    if (auth(pass))
    {
        std::cout << "请输入您的新密码" << std::endl;
        std::cin >> pass;
        usrPassWord = encryp(pass);
        return true;
    }
    else
    {
        return false;
    }
}
//long long int BaseUsr::totalNum = 0;
void BaseUsr::storage()
{
    Json::Value temp;
    Json::StreamWriterBuilder fwbuilder;
    temp["usrID"] = usrId;

    temp["usrName"] = usrName;
    temp["usrPass"] = usrPassWord;//使用哈希表！
    auto enumToString = [this]()->string {switch (this->usrType) {
                                            case USRTYPE::customer:return "customer";
                                            case USRTYPE::businessman:return"businessman";
                                            case USRTYPE::newUsr: return "sd";
}};
    temp["usrType"] = enumToString();
    //string out = temp.toStyledString();
    std::ofstream fout{"ALL_USR.txt",std::ios_base::app};
    auto jsonWriter(fwbuilder.newStreamWriter());
    jsonWriter->write(temp,&fout);
    fout.close();
}

bool BaseUsr::auth(std::string passwd)
{
    /*unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    std::ostringstream e;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        e.put(hash[i]);
    }
    std::string en_passwd = e.str();
    return usrPassWord==en_passwd;*/
    std::string enPassWord=encryp(passwd);
    return usrPassWord == enPassWord;
}

std::string BaseUsr::getUsrPassWord()
{
    return usrPassWord;
}

std::string BaseUsr::getUsrName()
{
    return usrName;
}

std::string BaseUsr::encryp(const std::string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    std::ostringstream e;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        e.put(hash[i]);
    }
    std::string en_passwd = e.str();
    return en_passwd;
}

string BaseUsr::tosting()
{
    auto enumToString = [usrType=this->usrType]()->string {switch (usrType) {
                                            case USRTYPE::customer:return "customer";
                                            case USRTYPE::businessman:return"businessman";
                                            case USRTYPE::newUsr: return "sd";

}};  
    std::cout << "ID:   " << usrId << "\nName:  " << usrName << "\nType:    " << enumToString() <<"\npd"<<usrPassWord<< std::endl;

    return string();
}

BaseUsr::BaseUsr(std::string name, std::string pd)
{
    usrName = name;
    usrPassWord = encryp(pd);
    isLogin = true;
}
BaseUsr::~BaseUsr()
{}


void BaseUsr::getMoney()
{
    std::cout << "只有用户用钱！！"<<std::endl;
}

void BaseUsr::getGoods()
{
    std::cout << "只有商家有货物" << std::endl;
}

void BaseUsr::changeGoods()
{
    std::cout << "只有商家能改货" << std::endl;
}
