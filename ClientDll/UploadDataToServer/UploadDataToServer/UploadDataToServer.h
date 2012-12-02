#pragma once
#ifdef UPLOADDATATOSERVER_EXPORTS
#define UPLOADDATATOSERVER_API  __declspec(dllexport)
#else
#define UPLOADDATATOSERVER_API __declspec(dllimport)
#endif
#include <WinSock.h>
#include <Windows.h>
#include<stdio.h>
#include "D:\xampp\mysql\include\mysql.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class UPLOADDATATOSERVER_API  UploadDataToServer
{
public:
	UploadDataToServer(const char *db_host, const int db_port);
	~UploadDataToServer(void);
	int connectToDatabase();
	//批量插入数据，从文件中读取
	int readAndWriteDatabase(const char *base_path, const char *sim_name, int sim_id);
	void closeDatabase();

private:
	int batchInsertIntoDatabase(const char *filename, int sim_id);
	//查找基目录下符合条件的所有文件名，并返回文件名列表
	int  findFileList(const char *base_path, const char *sim_name);
private:
	//数据库相关
	char m_user_name[20];		//数据库用户名
	char m_user_pw[20];			//数据库密码
	char m_db_name[20];		//数据库名
	char m_db_host[20];			//数据库服务器名（域名或ip）
	int m_db_port;					//数据库端口号
	MYSQL m_obj_sql;				//保存数据的句柄

	//文件相关
	char m_file_path[50];			//文件路径和文件名
	char m_sim_name[50];		//本次仿真的仿真名
	vector <string> m_fileList;	//本次仿真内容的文件名列表

};



