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
    ViewManger& viewManger = ViewManger::getInstance();
    std::regex txt_regex("[123]");
    input(choice, "1\tµÇÂ¼\n2\t×¢²á\n3\tÍË³ö", txt_regex);
    enum class MAINEVENT
    {
        login = 1,
        signUp = 2,
        logOut = 3
    };
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