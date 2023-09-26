#ifndef MY_SQL_H
#define MY_SQL_H

#include <iostream>
#include <mysql/mysql.h>

class Mysql
{
	std::string ip;
	std::string Name;  //  登录用户名
	std::string Pwd;	 //  密码
	std::string Use;  //  使用的数据库名称
	MYSQL *mysql;  //  mysql对象
public:
	Mysql(std::string ip,std::string name,std::string pwd,std::string use);
	~Mysql(void);
	int insert(std::string table,std::string str);  //  插入数据，(表名，数据)
	
	MYSQL_RES *show(std::string table);  //  获取table的二维表
	
	size_t field(void);  //  获取列数
	
	MYSQL_ROW get_row(MYSQL_RES *res);  //  获取行
	
	void input(std::string str);  //  任意输入
};

#endif
