// TestDll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "..\UploadDataToServer\UploadDataToServer\UploadDataToServer.h"
#pragma comment(lib, "UploadDataToServer.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	UploadDataToServer server("localhost", 3306);
	server.connectToDatabase();
	if (server.readAndWriteDatabase(".\\","�������ʵ��1",4) != 0)
	{
		printf("read And Write Database failed\n");
	}
	server.closeDatabase();
	printf("press any key to exit...\n");
	char ch;
	scanf("%c",&ch);
	return 0;
}

