#ifndef EMIS_H
#define EMIS_H

#include "manager_view_impl.h"

#define IP ("127.0.0.1")  //  连接 MySQL 时的IP
#define USER ("user")  //  MySQL 用户名
#define PWD ("123456")  //  MySQL 密码
#define MANAGER_DB ("emis")  //  表manager 保存的 数据库名
#define DEPARTMENT_DB ("emis")  //  表department 保存的 数据库名
#define EMPLOYEE_DB ("emis")  //  表employee 保存的 数据库名

#define MANAGER_TABLE ("manager")  //  保存管理员的表名
#define DEPARTMENT_TABLE ("department")  //  保存部门的表名
#define EMPLOYEE_TABLE ("employee")  //  保存员工的表名

extern int mgrid,deptid,empid;

class Emis
{
	ManagerView *mgrView;
	static Emis emis;
	Emis(void);
	Emis(const Emis& that){};
public:
	~Emis(void);
	static Emis& get_emis(void);
	void start_emis(void);
};

#endif
