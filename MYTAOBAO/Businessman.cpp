#include "Businessman.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios_base;

long long int Businessman::totalId = 0;
USRTYPE Businessman::type = USRTYPE::businessman;
string Businessman::storageAddress = ".";
Businessman::Businessman(std::string name, std::string PassWd)
    :BaseUsr{name,PassWd}
{
    id = totalId;
    totalId++;
    std::cout<<""
}

Businessman::Businessman()
{
}

void Businessman::storage()
{
}

bool Businessman::login()
{
    return false;
}

USRTYPE Businessman::getType()
{
    return USRTYPE();
}

void Businessman::setAddress(std::string newAddress)
{
}

std::string Businessman::getAddress()
{
    return std::string();
}

void Businessman::discount()
{
}

void Businessman::setGoods()
{
}
