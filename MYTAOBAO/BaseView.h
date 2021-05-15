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
    //std::unique_ptr<Businessman>Bus(new Businessman()) ;
    //static std::unique_ptr<BaseUsr> Usr{ std::make_unique<BaseUsr>() };
    inline static std::unique_ptr<Businessman> Bus{ std::make_unique<Businessman>() };//�������������static
    inline static std::unique_ptr<Customer>Cus{ std::make_unique<Customer>() };
private:
    static std::string logoAddress;
    static std::string goodsAddress;

};




