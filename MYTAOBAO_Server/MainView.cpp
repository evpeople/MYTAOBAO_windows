#include "MainView.h"
#include"Views.h"
#include"ViewManger.h"
#include <iostream>

using namespace std;
void MainView::show()
{
    showLogo();
    viewInput();
}

void MainView::viewInput()
{
    int choice;
    int sd = getId();
    std::regex txt_regex("[123]");
    input(choice, "1\t��¼\n2\tע��\n3\t�˳�", txt_regex);
    cout << "###########" << endl;
    //cout << a[1]<<"sa" << choice << "sadas" << endl;
    enum class MAINEVENT
    {
        login = 1,
        signUp = 2,
        logOut = 3
    };
    ViewManger& viewManger = ViewManger::getInstance(getId());
    switch ((MAINEVENT)choice)
    {
    case MAINEVENT::login:
        viewManger.setNext(make_unique<LoginView>());
        break;
    case MAINEVENT::signUp:
        viewManger.setNext(make_unique<SignUpView>());
        break;
    case MAINEVENT::logOut:
        viewManger.setNext(make_unique<LogoutView>());
        break;
    default:
        break;
    }
}