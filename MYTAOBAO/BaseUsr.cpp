#include "BaseUsr.h"
#include<iostream>
#include <openssl/sha.h>
long long int BaseUsr::totalNum = 0;
void BaseUsr::storage()
{

}

bool BaseUsr::auth(string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    string en_passwd = string((char*)hash);
    return usrPassWord==en_passwd;
}

string BaseUsr::encryp(const string passwd)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, passwd.c_str(), passwd.size());
    SHA256_Final(hash, &sha256);
    string en_passwd = string((char*)hash);
    return en_passwd;
}

string BaseUsr::tosting()
{
    std::cout << "ID:   " << usrId << "\nName:  " << usrName << "\nPassWord:    " << usrPassWord << std::endl;
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
