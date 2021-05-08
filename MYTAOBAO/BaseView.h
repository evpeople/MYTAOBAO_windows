#pragma once
#include<string>
class BaseView 
{
    /*
    ��󽫴����õ����ݷ������������ÿ������������ݴ�����
    ֮������������߼������󣬸�����һ���࣬���������������˴�������ͼ�����
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

private:
    int b;
    static std::string logoAddress;
    static std::string goodsAddress;

};
