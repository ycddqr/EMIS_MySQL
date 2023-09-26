#include "manager_mode_impl.h"
#include "emis.h"
#include "my_sql.h"

//  加载 MySQL 中数据到 mgrArr
void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	Mysql mysql(IP,USER,PWD,MANAGER_DB);  //  搞Mysql对象
	MYSQL_RES *res = mysql.show(MANAGER_TABLE);  //  获取 表manager 的二维表
	MYSQL_ROW row;  //  获取行首地址
	while((row = mysql.get_row(res)))
	{
		Manager manager;  //  临时变量保存数据
		//  row[i] 按照数据库中数据排列顺序
		manager.setId(atoi(row[0]));
		mgrid = manager.getId();
		manager.setName(row[1]);
		manager.setPwd(row[2]);
		//  存入向量 mgrArr
		mgrArr.push_back(manager);
	}
}

//  保存 mgrArr 到 MySQL 表manager
void ManagerModeImpl::save(vector<Manager>& mgrArr)
{
	Mysql mysql(IP,USER,PWD,MANAGER_DB);  //  搞个Mysql对象
	char buf[4096] = {};
	sprintf(buf,"truncate %s;",MANAGER_TABLE);
	mysql.input(buf);
	for(size_t i = 0; i < mgrArr.size(); i++)
	{
		//  遍历向量，存入所有数据
		sprintf(buf,"insert into %s values(%d,\"%s\",\"%s\");",MANAGER_TABLE,mgrArr[i].getId() ,mgrArr[i].getName(), mgrArr[i].getPwd());
		mysql.input(buf);
	}
}

