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
				//ֱ�Ӱ���˳�����Ϳ�����
			default:
				break;
			}
			break;
		}
	}
}
