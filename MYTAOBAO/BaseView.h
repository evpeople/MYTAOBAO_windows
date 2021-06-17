#pragma once
#include<string>
#include<regex>
#include<memory>
#include"Businessman.h"
#include"Customer.h"

class BaseView 
{
    /*
    ��󽫴���õ����ݷ������������ÿ������������ݴ���
    ֮������������߼�����󣬸�����һ���࣬���������������˴�������ͼ�����
    ������ͼ��Ӧ�ð����Լ��Ŀ���������ͬ����ͼ�಻ͬ�Ŀ�������
    �����еĿ�����������һ��ҳ�������
    ҳ����������õ���ģʽ
    ��Ҫά��һ��ans��string vector�����ͳһ�����vector��������
    ��show��ʱ��ȫ����Ҫshow��ǰ����Ʒ����չʾ���ԣ�
    */
public:
    virtual void show()=0 ;
    virtual void viewInput()=0  ;
    
    void showLogo();
    void showGoods();
    void static setAddress(std::string,std::string);
protected:
    virtual void input(int& choice, std::string help,std::regex regexString);
    virtual void input(std::string& choice, std::string help);
    static void input(double& num);
    static void input(long long int& num);
    static  void input(int& k);

    inline static std::unique_ptr<BaseUsr> Usr = nullptr;
    inline static std::unordered_map<std::string,Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string,std::vector<Json::Value>>GoodSearchFromType;
private:
    static std::string logoAddress;
    static std::string goodsAddress;
    
};




