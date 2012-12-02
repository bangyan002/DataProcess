#include "StdAfx.h"
#include "UploadDataToServer.h"


UploadDataToServer::UploadDataToServer(const char *db_host, const int db_port)
{
	strcpy_s(m_user_name, "sim_test");
	strcpy_s(m_user_pw, "sim_test");
	strcpy_s(m_db_name, "sim_test");

	if (db_host == NULL || db_port <= 0)
	{
		strcpy_s(m_db_host,"127.0.0.1");
		m_db_port = 3306;
	}
	else
	{
		strcpy_s(m_db_host,db_host );
		m_db_port = db_port;
	}
	mysql_init( &m_obj_sql );
}
UploadDataToServer::~UploadDataToServer(void)
{
		mysql_close(&m_obj_sql);	
}

void UploadDataToServer::closeDatabase()
{
		mysql_close(&m_obj_sql);
}

int UploadDataToServer::connectToDatabase()
{

	if (mysql_real_connect(&m_obj_sql,m_db_host,m_user_name,m_user_pw,m_db_name,m_db_port,NULL,0))
	{
		mysql_query(&m_obj_sql,"set NAMES gb2312");
		return 0;
	}
	else 
	{
		return -1;
	}
}


int UploadDataToServer::readAndWriteDatabase(const char* base_path, const char* sim_name, int sim_id)
{
	if (findFileList(base_path,sim_name) == 0)
	{
		for (vector<string>::iterator it = m_fileList.begin();
			it != m_fileList.end(); it++)
		{
			batchInsertIntoDatabase(it->c_str(),sim_id);
		}
		//使用完后，将文件列表清除
		for (vector<string>::iterator it = m_fileList.begin();
			it != m_fileList.end(); it++)
		{
			m_fileList.pop_back();
		}
	}
	else
	{
		return -1;
	}

}
int UploadDataToServer::batchInsertIntoDatabase(const char *filename, int sim_id)
{
	int returnFlag = 0;
	ifstream filefin;
	filefin.open(filename);
	if (!filefin)
	{
		return -1;
	}
	float pos_x, pos_y, pos_z;
	float spd_x, spd_y, spd_z;
	int index = 0;

	mysql_autocommit(&m_obj_sql,0);
	char sql[200] = {0};
	cout<<"begin batch insert....."<<endl;
	while(!filefin.eof())
	{
		if (filefin>>pos_x>>pos_y>>pos_z>>spd_x>>spd_y>>spd_z)
		{
			sprintf_s(sql,"insert into sim_data_x values (%d,%f,%f,%f,%f,%f,%f,%d);",
				index,pos_x,pos_y,pos_z,spd_x,spd_y,spd_z,sim_id);
			index++;
			mysql_query(&m_obj_sql, sql);	
		}
		else
		{
			returnFlag = -2;
			break;
		}

	}
	filefin.close();
	mysql_commit(&m_obj_sql);

	return returnFlag;

}

int UploadDataToServer::findFileList(const char *base_path, const char *sim_name)
{

	if (base_path == NULL || sim_name == NULL)
	{
		return -1;
	}
	
	WIN32_FIND_DATA findFileData; 
	HANDLE hFind=INVALID_HANDLE_VALUE;
	string direc(base_path);
	direc += "*.txt";
	hFind = FindFirstFile(direc.c_str(), &findFileData);
	if(hFind==INVALID_HANDLE_VALUE)                               //如果hFind句柄创建失败，输出错误信息  
	{  
		FindClose(hFind);   
		return -2;
	} 
	else
	{
		do 
		{
			if((findFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)==0)    //如果不是文件夹  
			{  
				string dataFile(findFileData.cFileName);
				int pos = dataFile.find_first_of('@');
				if (pos != -1 )
				{
					if (strcmp(dataFile.substr(0,pos).c_str(), sim_name) == 0)
					{
						m_fileList.push_back(dataFile);
					}
				}
			}  
		}while(FindNextFile(hFind,&findFileData)!=0) ;
		FindClose(hFind);
	}

	return 0;
}

