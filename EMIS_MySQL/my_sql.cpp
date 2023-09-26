#include "my_sql.h"
#include <cstring>
#include <cstdio>

void error_mysql(MYSQL *mysql)
{
	std::cout << mysql_errno(mysql) << ":" << mysql_error(mysql) << std::endl;
}

Mysql::Mysql(std::string ip,std::string name,std::string pwd,std::string use) : ip(ip),Name(name),Pwd(pwd),Use(use)
{
    mysql = mysql_init(NULL);
    //  MYSQL对象 连接服务器
    mysql = mysql_real_connect(mysql,ip.c_str(),Name.c_str(),Pwd.c_str(),Use.c_str(),3306,NULL,0);
    if(NULL == mysql) error_mysql(mysql);
}

Mysql::~Mysql(void)
{
	
}

int Mysql::insert(std::string table,std::string str)
{
	char buf[4096] = {};
	sprintf(buf,"insert into %s values(%s);",table.c_str(),str.c_str());
	return mysql_real_query(mysql,buf,strlen(buf));
}

MYSQL_RES *Mysql::show(std::string table)
{
	char buf[4096] = {};
	sprintf(buf,"select * from %s;",table.c_str());
	mysql_real_query(mysql,buf,strlen(buf));
	return mysql_store_result(mysql);
}

size_t Mysql::field(void)
{
	return mysql_field_count(mysql);
}

MYSQL_ROW Mysql::get_row(MYSQL_RES *res)
{
	return mysql_fetch_row(res);
}

void Mysql::input(std::string str)
{
	if(mysql_real_query(mysql,str.c_str(),str.size()))
	{
		//error_mysql(mysql);
		return;
	}
	//  获取查询结果  存储在二维表 res 中
	MYSQL_RES *res = mysql_store_result(mysql);
	if(NULL == res)
	{
		//error_mysql(mysql);
		return;
	}
	//  获取二维表列数
	size_t cnt = mysql_field_count(mysql);
	MYSQL_ROW row;
	while((row = mysql_fetch_row(res)))
	{
		//  从res中读取一行数据的首地址 row
		for(size_t i = 0; i < cnt; i++)
		{
			std::cout << row[i] << " ";
		}
		std::cout << std::endl;
	}
}
