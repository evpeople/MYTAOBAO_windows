#include "BaseUsr.h"
#include<iostream>
#include<fstream>
#include <openssl/sha.h>
#include<json/json.h>
void BaseUsr::discount()
{
    std::cout << "ֻ���̼ҿ��Դ���" << std::endl;
}
bool BaseUsr::changePassWord()
{
    std::cout << "��������ԭ��������" << std::endl;
    std::string pass;
    std::cin >> pass;
    if (auth(pass))
    {
        std::cout << "����������������" << std::endl;
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
    temp["usrPass"] = usrPassWord;//ʹ�ù�ϣ��
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
    std::cout << "ֻ���û���Ǯ����"<<std::endl;
}

void BaseUsr::getGoods()
{
    std::cout << "ֻ���̼��л���" << std::endl;
}

void BaseUsr::changeGoods()
{
    std::cout << "ֻ���̼��ܸĻ�" << std::endl;
}
