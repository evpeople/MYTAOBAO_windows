#pragma once
#include"BaseView.h"
class CartView :
    public BaseView
{
    virtual void show()override;
    virtual void viewInput()override;
    bool dealInput(std::string name, std::string pass, int choice);
private:
    void search();
    bool dealBuy();//todo: �������ѳ�֧���������۳�ת��Ǯ�ơ�remainΪ���˶���,Ǯû��
    //todo: Ǯ�û���ֵ��û����
    //todo: ����ҳ��Ļ���
    void search(std::string, Json::Value& ansGood);
    void search(std::string, std::vector<Json::Value>& ansGoods);
};
