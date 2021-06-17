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
    std::regex txt_regex("[12]");
    input(choice, "1\tµÇÂ¼\n2\t×¢²á\n", txt_regex);
    cout << "###########" << endl;
    //cout << a[1]<<"sa" << choice << "sadas" << endl;
    enum class MAINEVENT
    {
        login = 1,
        signUp = 2
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
    default:
        break;
    }
}