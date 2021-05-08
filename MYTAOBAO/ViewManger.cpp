#include "ViewManger.h"

void ViewManger::start()
{
	while (viewNext)
	{
		viewCurrent = std::move(viewNext);
		viewCurrent->show();
	}
}
