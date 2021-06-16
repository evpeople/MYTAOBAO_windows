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
    virtual void show() ;
    virtual void viewInput()  ;
    
    int getId();
    void setId(int id);
    void showLogo();
    void showGoods();
    void static setAddress(std::string,std::string);
protected:
    int id;
    virtual void input(int& choice, std::string help,std::regex regexString);
    virtual void input(std::string& choice, std::string help);
    static void input(double& num);
    static void input(long long int& num);
    static  void input(int& k);

    //std::unique_ptr<Businessman>Bus(new Businessman()) ;
    inline static std::unique_ptr<BaseUsr> Usr = nullptr;
    inline static std::unordered_map<std::string,Json::Value>GoodSearchFromName;
    inline static std::unordered_map<std::string,std::vector<Json::Value>>GoodSearchFromType;
    //inline static std::unique_ptr<Businessman> Bus{ std::make_unique<Businessman>() };//�������������static
    //inline static std::unique_ptr<Customer>Cus{ std::make_unique<Customer>() };
private:
    static std::string logoAddress;
    static std::string goodsAddress;
    
};




