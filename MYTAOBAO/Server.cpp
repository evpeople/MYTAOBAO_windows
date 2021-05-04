#include "Server.h"

void Server::start()
{
	char choice;
	std::cin >> choice;
	EVENT a;
	LOGINEVENT b;
	while (true)
	{
		switch (a)
		{
		case EVENT::login:
			break;
		case EVENT::getIn:
			switch (b)
			{
				//直接按照顺序读入就可以了
			default:
				break;
			}
			break;
		}
	}
}
