#include "MainView.h"
#include"Views.h"
#include"ViewManger.h"
#include <iostream>

using namespace std;
void MainView::show()
{
    showLogo();
}

void MainView::viewInput()
{
    int choice;
    ViewManger& viewManger = ViewManger::getInstance();
    std::regex txt_regex("[12]");
    input(choice, "1\tµÇÂ¼\n2\t×¢²á\n", txt_regex);
    enum class MAINEVENT
    {
        login = 1,
        signUp = 2
    };
    switch ((MAINEVENT)choice)
    {
    case MAINEVENT::login:
        viewManger.setNext(make_unique<BusResultView>());
        break;
    case MAINEVENT::signUp:
        viewManger.setNext(make_unique<BusResultView>());
        break;
    default:
        break;
    }

}
