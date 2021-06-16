// MYTAOBAO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//todo: 所有输入函数的检查
//todo: C/S架构所有操作的返回值（异常处理）
//todo: 输入改为输入一行
//todo: 商人提供不登陆但展示的接口

#include <fstream>
#include<iostream>
#include <WS2tcpip.h>
#include "BaseUsr.h"
#include"Customer.h"
#include<json/json.h>
#include "Server.h"
#pragma comment(lib, "Ws2_32.lib")




int main()
{
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);
    std::cout << "欢迎来到我的淘世界！！！";
    
    
    //SOCKET listenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //sockaddr_in sockAddr;
    //memset(&sockAddr, 0, sizeof(sockAddr));  
    //sockAddr.sin_family = PF_INET;  

    // inet_pton(AF_INET,"127.0.0.1", &sockAddr.sin_addr);
    //sockAddr.sin_port = htons(3234);  
    //bind(listenSocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //listen(listenSocket, 20);

    //SOCKADDR clntAddr;
    //int nSize = sizeof(SOCKADDR);
    //SOCKET clntSock = accept(listenSocket, (SOCKADDR*)&clntAddr, &nSize);
    

    Server a = Server();
    
    //a.setSockAdd(clntAddr);
    //a.setSocket(clntSock);

    a.start(1);
    //    while (1)
//    {
//        
//        cin >> event;
//    }
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
