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
	//�����������ݣ����ļ��ж�ȡ
	int readAndWriteDatabase(const char *base_path, const char *sim_name, int sim_id);
	void closeDatabase();

private:
	int batchInsertIntoDatabase(const char *filename, int sim_id);
	//���һ�Ŀ¼�·��������������ļ������������ļ����б�
	int  findFileList(const char *base_path, const char *sim_name);
private:
	//���ݿ����
	char m_user_name[20];		//���ݿ��û���
	char m_user_pw[20];			//���ݿ�����
	char m_db_name[20];		//���ݿ���
	char m_db_host[20];			//���ݿ����������������ip��
	int m_db_port;					//���ݿ�˿ں�
	MYSQL m_obj_sql;				//�������ݵľ��

	//�ļ����
	char m_file_path[50];			//�ļ�·�����ļ���
	char m_sim_name[50];		//���η���ķ�����
	vector <string> m_fileList;	//���η������ݵ��ļ����б�

};



