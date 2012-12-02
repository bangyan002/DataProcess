// TestDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "..\UploadDataToServer\UploadDataToServer\UploadDataToServer.h"
#pragma comment(lib, "UploadDataToServer.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	UploadDataToServer server("localhost", 3306);
	server.connectToDatabase();
	if (server.readAndWriteDatabase(".\\","仿真测试实验1",4) != 0)
	{
		printf("read And Write Database failed\n");
	}
	server.closeDatabase();
	printf("press any key to exit...\n");
	char ch;
	scanf("%c",&ch);
	return 0;
}

